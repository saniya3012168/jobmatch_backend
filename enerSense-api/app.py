# app.py
from flask import Flask, request, jsonify
import pandas as pd
from load_forecasting_agent import LoadForecastingAgent
from der_optimizer_agent import DEROptimizerAgent

app = Flask(__name__)

@app.route('/')
def home():
    return "EnerSense API is running."

@app.route('/forecast', methods=['POST'])
def forecast():
    try:
        data = request.json  # expects a list of rows from Relay/Sheets
        df = pd.DataFrame(data)
        
        agent = LoadForecastingAgent()
        agent.load_model('models/load_forecaster.pkl')  # Pre-trained model
        predictions = agent.forecast(df)

        return jsonify({'forecast': predictions.tolist()})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/optimize', methods=['POST'])
def optimize():
    try:
        data = request.json
        df = pd.DataFrame(data)
        
        optimizer = DEROptimizerAgent()
        result_df = optimizer.optimize(df)

        return jsonify(result_df.to_dict(orient='records'))
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
