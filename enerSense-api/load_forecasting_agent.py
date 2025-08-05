# load_forecasting_agent.py
import pandas as pd
import joblib
from sklearn.ensemble import GradientBoostingRegressor

class LoadForecastingAgent:
    def __init__(self):
        self.model = None

    def load_model(self, path='models/load_forecaster.pkl'):
        self.model = joblib.load(path)

    def forecast(self, input_df):
        input_df['hour'] = pd.to_datetime(input_df['timestamp']).dt.hour
        input_df['day_of_week'] = pd.to_datetime(input_df['timestamp']).dt.dayofweek
        features = ['hour', 'day_of_week', 'temperature', 'humidity', 'wind_speed']
        return self.model.predict(input_df[features])
