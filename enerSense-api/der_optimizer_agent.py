# der_optimizer_agent.py
import pandas as pd

class DEROptimizerAgent:
    def __init__(self, battery_capacity_kwh=10, battery_efficiency=0.9):
        self.battery_capacity = battery_capacity_kwh
        self.efficiency = battery_efficiency
        self.state_of_charge = battery_capacity_kwh / 2

    def optimize(self, df):
        results = []
        for _, row in df.iterrows():
            load = row['load_kwh']
            solar = row['solar_gen_kwh']
            price = row['price_per_kwh']

            solar_used = min(load, solar)
            net_load = load - solar_used
            battery_discharge = 0
            grid_draw = 0

            if net_load > 0:
                battery_discharge = min(net_load, self.state_of_charge)
                self.state_of_charge -= battery_discharge
                grid_draw = net_load - battery_discharge
            else:
                excess_solar = -net_load
                charge = min(excess_solar, self.battery_capacity - self.state_of_charge)
                self.state_of_charge += charge * self.efficiency

            results.append({
                'timestamp': row['timestamp'],
                'load': load,
                'solar_used': solar_used,
                'battery_discharge': battery_discharge,
                'grid_draw': grid_draw,
                'state_of_charge': self.state_of_charge,
                'cost': grid_draw * price
            })

        return pd.DataFrame(results)
