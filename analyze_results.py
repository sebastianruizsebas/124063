#!/usr/bin/env python3
"""
CNS F25 Project 2: Rod Achromatopsia Analysis
Analyzes simulation results to compute dynamic range and power-law fits

Based on Publio et al. 2009 methodology
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import pearsonr
import glob
import os

class RetinalDynamicRangeAnalyzer:
    """
    Analyzes retinal ganglion cell responses to compute:
    1. Dynamic range A using I10 and I90 percentiles
    2. Power-law fit F = c * I^a
    3. Comparison between scotopic baseline and rod achromatopsia
    """
    
    def __init__(self):
        self.data = {}
        
    def load_data(self, filename):
        """Load simulation results from .dat file"""
        print(f"Loading {filename}...")
        
        data = {'flash': [], 'spike_count': [], 'firing_rate': []}
        
        with open(filename, 'r') as f:
            for line in f:
                if line.startswith('#'):
                    continue
                parts = line.strip().split()
                if len(parts) >= 3:
                    data['flash'].append(float(parts[0]))
                    data['spike_count'].append(int(parts[1]))
                    data['firing_rate'].append(float(parts[2]))
        
        data['flash'] = np.array(data['flash'])
        data['spike_count'] = np.array(data['spike_count'])
        data['firing_rate'] = np.array(data['firing_rate'])
        
        print(f"  Loaded {len(data['flash'])} data points")
        return data
    
    def compute_dynamic_range(self, flash, firing_rate):
        """
        Compute dynamic range A using I10 and I90 percentiles
        Formula: A = log10(I_90 / I_10)
        
        Where I_10 and I_90 are flash intensities producing 10% and 90%
        of the maximum firing rate response
        """
        if len(firing_rate) == 0:
            return np.nan, np.nan, np.nan
        
        max_rate = np.max(firing_rate)
        
        if max_rate == 0:
            return np.nan, np.nan, np.nan
        
        # Target firing rates (10% and 90% of maximum)
        target_10 = 0.1 * max_rate
        target_90 = 0.9 * max_rate
        
        # Find flash intensities closest to these targets
        idx_10 = np.argmin(np.abs(firing_rate - target_10))
        idx_90 = np.argmin(np.abs(firing_rate - target_90))
        
        I_10 = flash[idx_10]
        I_90 = flash[idx_90]
        
        # Compute dynamic range
        if I_10 > 0:
            A = np.log10(I_90 / I_10)
        else:
            A = np.nan
        
        return A, I_10, I_90
    
    def power_law(self, I, c, a):
        """Power law function: F = c * I^a"""
        return c * np.power(I, a)
    
    def fit_power_law(self, flash, firing_rate):
        """
        Fit F = c * I^a to firing rate vs flash intensity
        Returns: c, a, R^2, RMSE
        """
        # Filter out zero values for log-log fitting
        valid_idx = (flash > 0) & (firing_rate > 0)
        
        if np.sum(valid_idx) < 3:
            return np.nan, np.nan, np.nan, np.nan
        
        flash_valid = flash[valid_idx]
        rate_valid = firing_rate[valid_idx]
        
        try:
            # Fit power law
            popt, pcov = curve_fit(self.power_law, flash_valid, rate_valid,
                                   p0=[1.0, 0.5], maxfev=10000)
            c, a = popt
            
            # Compute goodness of fit
            rate_pred = self.power_law(flash_valid, c, a)
            
            # R^2
            ss_res = np.sum((rate_valid - rate_pred)**2)
            ss_tot = np.sum((rate_valid - np.mean(rate_valid))**2)
            r_squared = 1 - (ss_res / ss_tot) if ss_tot > 0 else 0
            
            # RMSE
            rmse = np.sqrt(np.mean((rate_valid - rate_pred)**2))
            
            return c, a, r_squared, rmse
            
        except Exception as e:
            print(f"  Warning: Power law fit failed: {e}")
            return np.nan, np.nan, np.nan, np.nan
    
    def analyze_flash_sweep(self, filename):
        """Analyze a single flash intensity sweep file"""
        data = self.load_data(filename)
        
        # Extract parameters from filename
        params = self.parse_filename(filename)
        
        # Compute dynamic range
        A, I_10, I_90 = self.compute_dynamic_range(data['flash'], data['firing_rate'])
        
        # Fit power law
        c, a, r2, rmse = self.fit_power_law(data['flash'], data['firing_rate'])
        
        results = {
            'filename': filename,
            'params': params,
            'data': data,
            'dynamic_range_A': A,
            'I_10': I_10,
            'I_90': I_90,
            'power_law_c': c,
            'power_law_exponent': a,
            'power_law_R2': r2,
            'power_law_RMSE': rmse
        }
        
        print(f"\nAnalysis Results:")
        print(f"  Dynamic Range A = {A:.3f}")
        print(f"  I_10 = {I_10:.1f} pA, I_90 = {I_90:.1f} pA")
        print(f"  Power law: F = {c:.3f} * I^{a:.3f}")
        print(f"  R^2 = {r2:.3f}, RMSE = {rmse:.3f}")
        
        return results
    
    def parse_filename(self, filename):
        """Extract parameters from filename"""
        params = {}
        basename = os.path.basename(filename)
        
        # Extract Abg
        if 'Abg' in basename:
            try:
                abg_str = basename.split('Abg')[1].split('_')[0]
                params['Abg'] = float(abg_str)
            except:
                params['Abg'] = 0
        
        # Extract gh
        if 'gh' in basename:
            try:
                gh_str = basename.split('gh')[1].split('_')[0]
                params['gh'] = float(gh_str)
            except:
                params['gh'] = np.nan
        
        # Extract Kr
        if 'Kr' in basename:
            try:
                kr_str = basename.split('Kr')[1].split('_')[0]
                params['Kr'] = int(kr_str)
            except:
                params['Kr'] = np.nan
        
        # Extract Ka
        if 'Ka' in basename:
            try:
                ka_str = basename.split('Ka')[1].split('_')[0]
                params['Ka'] = int(ka_str)
            except:
                params['Ka'] = np.nan
        
        # Extract cones status
        if 'cones0' in basename:
            params['cones'] = 0  # Rod achromatopsia
        elif 'cones1' in basename:
            params['cones'] = 1  # Normal
        else:
            params['cones'] = np.nan
        
        return params
    
    def plot_flash_response(self, results, save_path=None):
        """Plot F-I curve with power law fit"""
        data = results['data']
        params = results['params']
        
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
        
        # Linear plot
        ax1.plot(data['flash'], data['firing_rate'], 'o-', label='Data', markersize=8)
        
        # Power law fit
        if not np.isnan(results['power_law_c']):
            flash_fit = np.linspace(data['flash'].min(), data['flash'].max(), 100)
            rate_fit = self.power_law(flash_fit, results['power_law_c'], 
                                     results['power_law_exponent'])
            ax1.plot(flash_fit, rate_fit, '--', label=f'Fit: F={results["power_law_c"]:.2f}*I^{results["power_law_exponent"]:.2f}')
        
        ax1.set_xlabel('Flash Intensity (pA)', fontsize=12)
        ax1.set_ylabel('Firing Rate (Hz)', fontsize=12)
        ax1.set_title(f'F-I Curve (Abg={params.get("Abg", 0)} pA, gh={params.get("gh", "?")} nS)', fontsize=12)
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Log-log plot
        valid_idx = (data['flash'] > 0) & (data['firing_rate'] > 0)
        ax2.loglog(data['flash'][valid_idx], data['firing_rate'][valid_idx], 'o', 
                   markersize=8, label='Data')
        
        if not np.isnan(results['power_law_c']):
            flash_fit = np.logspace(np.log10(data['flash'][valid_idx].min()), 
                                   np.log10(data['flash'][valid_idx].max()), 100)
            rate_fit = self.power_law(flash_fit, results['power_law_c'], 
                                     results['power_law_exponent'])
            ax2.loglog(flash_fit, rate_fit, '--', 
                      label=f'Slope={results["power_law_exponent"]:.2f}')
        
        ax2.set_xlabel('Flash Intensity (pA)', fontsize=12)
        ax2.set_ylabel('Firing Rate (Hz)', fontsize=12)
        ax2.set_title(f'Log-Log Plot (A={results["dynamic_range_A"]:.2f})', fontsize=12)
        ax2.legend()
        ax2.grid(True, alpha=0.3, which='both')
        
        # Add text box with results
        textstr = f'Dynamic Range A = {results["dynamic_range_A"]:.3f}\n'
        textstr += f'Exponent a = {results["power_law_exponent"]:.3f}\n'
        textstr += f'R² = {results["power_law_R2"]:.3f}\n'
        textstr += f'Cones: {"ON" if params.get("cones", 1) == 1 else "OFF"}'
        ax2.text(0.05, 0.95, textstr, transform=ax2.transAxes, fontsize=10,
                verticalalignment='top', bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))
        
        plt.tight_layout()
        
        if save_path:
            plt.savefig(save_path, dpi=150, bbox_inches='tight')
            print(f"Figure saved to {save_path}")
        
        return fig
    
    def compare_conditions(self, results_list, save_path=None):
        """Compare multiple conditions (e.g., different Abg levels)"""
        fig, axes = plt.subplots(2, 2, figsize=(14, 10))
        
        # Collect data for comparison
        abg_vals = []
        A_vals = []
        exponent_vals = []
        r2_vals = []
        
        for result in results_list:
            params = result['params']
            abg_vals.append(params.get('Abg', 0))
            A_vals.append(result['dynamic_range_A'])
            exponent_vals.append(result['power_law_exponent'])
            r2_vals.append(result['power_law_R2'])
        
        # Plot 1: F-I curves overlay
        ax1 = axes[0, 0]
        for result in results_list:
            data = result['data']
            params = result['params']
            label = f'Abg={params.get("Abg", 0)} pA'
            ax1.plot(data['flash'], data['firing_rate'], 'o-', label=label)
        ax1.set_xlabel('Flash Intensity (pA)')
        ax1.set_ylabel('Firing Rate (Hz)')
        ax1.set_title('F-I Curves Comparison')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Plot 2: Dynamic range vs background
        ax2 = axes[0, 1]
        ax2.plot(abg_vals, A_vals, 'o-', markersize=10, linewidth=2)
        ax2.set_xlabel('Background Current Abg (pA)')
        ax2.set_ylabel('Dynamic Range A')
        ax2.set_title('Dynamic Range vs Background')
        ax2.grid(True, alpha=0.3)
        ax2.axhline(y=0.5, color='r', linestyle='--', label='Critical exponent')
        ax2.legend()
        
        # Plot 3: Power law exponent vs background
        ax3 = axes[1, 0]
        ax3.plot(abg_vals, exponent_vals, 's-', markersize=10, linewidth=2, color='green')
        ax3.set_xlabel('Background Current Abg (pA)')
        ax3.set_ylabel('Power Law Exponent a')
        ax3.set_title('Power Law Exponent vs Background')
        ax3.grid(True, alpha=0.3)
        ax3.axhline(y=0.5, color='r', linestyle='--', label='Expected ~0.5')
        ax3.legend()
        
        # Plot 4: Fit quality vs background
        ax4 = axes[1, 1]
        ax4.plot(abg_vals, r2_vals, '^-', markersize=10, linewidth=2, color='orange')
        ax4.set_xlabel('Background Current Abg (pA)')
        ax4.set_ylabel('Power Law Fit R²')
        ax4.set_title('Fit Quality vs Background')
        ax4.grid(True, alpha=0.3)
        ax4.set_ylim([0, 1.05])
        
        plt.tight_layout()
        
        if save_path:
            plt.savefig(save_path, dpi=150, bbox_inches='tight')
            print(f"Comparison figure saved to {save_path}")
        
        return fig
    
    def generate_summary_report(self, results_list, output_file='analysis_summary.txt'):
        """Generate text summary of all analyses"""
        with open(output_file, 'w') as f:
            f.write("=" * 80 + "\n")
            f.write("Rod Achromatopsia Simulation Analysis Summary\n")
            f.write("CNS F25 Project 2\n")
            f.write("=" * 80 + "\n\n")
            
            # Group by condition
            scotopic = [r for r in results_list if r['params'].get('cones', 1) == 1]
            achromatopsia = [r for r in results_list if r['params'].get('cones', 1) == 0]
            
            f.write("SCOTOPIC BASELINE (Cones ON)\n")
            f.write("-" * 80 + "\n")
            for result in scotopic:
                self._write_result_summary(f, result)
            
            f.write("\n\nROD ACHROMATOPSIA (Cones OFF)\n")
            f.write("-" * 80 + "\n")
            for result in achromatopsia:
                self._write_result_summary(f, result)
            
            # Comparison
            if scotopic and achromatopsia:
                f.write("\n\nCOMPARISON\n")
                f.write("-" * 80 + "\n")
                avg_A_scotopic = np.nanmean([r['dynamic_range_A'] for r in scotopic])
                avg_A_achromatopsia = np.nanmean([r['dynamic_range_A'] for r in achromatopsia])
                f.write(f"Average Dynamic Range:\n")
                f.write(f"  Scotopic: {avg_A_scotopic:.3f}\n")
                f.write(f"  Achromatopsia: {avg_A_achromatopsia:.3f}\n")
                f.write(f"  Reduction: {((avg_A_scotopic - avg_A_achromatopsia) / avg_A_scotopic * 100):.1f}%\n")
        
        print(f"\nSummary report written to {output_file}")
    
    def _write_result_summary(self, f, result):
        """Helper to write individual result summary"""
        params = result['params']
        f.write(f"\nFile: {os.path.basename(result['filename'])}\n")
        f.write(f"  Abg = {params.get('Abg', 0)} pA, ")
        f.write(f"gh = {params.get('gh', '?')} nS, ")
        f.write(f"Kr = {params.get('Kr', '?')}, ")
        f.write(f"Ka = {params.get('Ka', '?')}\n")
        f.write(f"  Dynamic Range A = {result['dynamic_range_A']:.3f}\n")
        f.write(f"  Power Law: F = {result['power_law_c']:.3f} * I^{result['power_law_exponent']:.3f}\n")
        f.write(f"  Fit Quality: R² = {result['power_law_R2']:.3f}, RMSE = {result['power_law_RMSE']:.3f}\n")


def main():
    """Main analysis workflow"""
    print("=" * 80)
    print("Rod Achromatopsia Simulation Analysis")
    print("=" * 80)
    
    analyzer = RetinalDynamicRangeAnalyzer()
    
    # Find all flash sweep result files
    flash_sweep_files = glob.glob("results_flash_sweep_*.dat")
    
    if not flash_sweep_files:
        print("\nNo result files found!")
        print("Please run the NEURON simulation first to generate .dat files")
        return
    
    print(f"\nFound {len(flash_sweep_files)} result files")
    
    # Analyze each file
    all_results = []
    for filename in sorted(flash_sweep_files):
        print(f"\n{'='*80}")
        result = analyzer.analyze_flash_sweep(filename)
        all_results.append(result)
        
        # Plot individual result
        plot_name = filename.replace('.dat', '_plot.png')
        analyzer.plot_flash_response(result, save_path=plot_name)
    
    # Group results by condition
    scotopic_results = [r for r in all_results if r['params'].get('cones', 1) == 1]
    achromatopsia_results = [r for r in all_results if r['params'].get('cones', 1) == 0]
    
    # Generate comparison plots
    if scotopic_results:
        print("\nGenerating scotopic baseline comparison...")
        analyzer.compare_conditions(scotopic_results, 
                                   save_path='scotopic_baseline_comparison.png')
    
    if achromatopsia_results:
        print("\nGenerating rod achromatopsia comparison...")
        analyzer.compare_conditions(achromatopsia_results, 
                                   save_path='rod_achromatopsia_comparison.png')
    
    # Generate summary report
    analyzer.generate_summary_report(all_results)
    
    print("\n" + "=" * 80)
    print("Analysis complete!")
    print("=" * 80)
    plt.show()


if __name__ == "__main__":
    main()
