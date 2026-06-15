# Air-Quality-Index-ISPU-Prediction-Using-Linear-Regression-on-ESP32
Predicting Jakarta Air Quality Index (ISPU) values using Linear Regression trained on historical air pollution data and deployed to ESP32 for lightweight embedded inference.

# Project Overview
Air quality is an important environmental factor that directly affects public health. High concentrations of pollutants such as PM10, SO₂, CO, O₃, and NO₂ can lead to respiratory diseases and other health problems.

This project uses historical ISPU data from Jakarta to train a Linear Regression model capable of estimating the maximum air quality index (MAX) based on pollutant measurements. The trained model is then converted into C++ code using m2cgen and deployed to an ESP32 microcontroller for lightweight embedded inference.

The project was developed as a final assignment for the Pattern Recognition course at Brawijaya University.

# Dataset
Source:
https://www.kaggle.com/datasets/senadu34/air-quality-index-in-jakarta-2010-2021

Dataset characteristics:
- Period: 2010–2025
- Original records: 5,538
- Cleaned records: 4,874

Features:
- PM10 (Particulate Matter 10)
- SO₂ (Sulfur Dioxide)
- CO (Carbon Monoxide)
- O₃ (Ground-Level Ozone)
- NO₂ (Nitrogen Dioxide)

Target:
- MAX (Maximum Air Quality Index Value)

# Data Preprocessing
The following preprocessing steps were applied:
1. Remove PM2.5 column due to excessive missing values.
2. Remove records labeled as "TIDAK ADA DATA".
3. Remove remaining rows containing missing values.

# Machine Learning Model
Algorithm:
- Linear Regression (Scikit-Learn)

Training Split:
- Training Data: 80% (3,899 samples)
- Testing Data: 20% (975 samples)

Model Equation:
```cpp
MAX =
-1.094754893157429
+ (0.471016 * PM10)
+ (0.462222 * SO2)
- (0.122609 * CO)
+ (0.728198 * O3)
+ (0.500774 * NO2);
```

# Model Performance
Evaluation results:
| Metric | Value |
|----------|----------|
| MAE | 13.2003 |
| RMSE | 16.8179 |
| R² Score | 82.75% |

The model explains approximately 82.75% of the variation in MAX values based on the five pollutant parameters.

# ESP32 Deployment
The trained Linear Regression model was converted into C++ using:

```python
m2cgen
```

The generated function was stored in:

```text
model_regresi.h
```

ESP32 receives pollutant values as input and performs local inference without requiring any machine learning libraries.

Example:

```cpp
double input[5] = {
    60,  // PM10
    10,  // SO2
    30,  // CO
    80,  // O3
    20   // NO2
};

double prediction = score(input);
```

Output:

```text
Prediksi MAX = 95.71
Kategori: SEDANG
```

---

# Limitations
- Input values are currently entered manually.
- No real-time air quality sensor integration.
- No API integration for live air quality data.
- Validation is based on historical datasets only.

# Future Improvements
- Integrate OpenWeather Air Pollution API or AQICN API.
- Add real-time data acquisition.
- Include meteorological features such as temperature, humidity, rainfall, and wind speed.
- Compare Linear Regression with Random Forest, XGBoost, and Decision Tree Regression.

# Demonstration Video
https://drive.google.com/file/d/1ytu77Kp1oGxfG3Suvtj88_kD6HZJ1K8e/view?usp=sharing

# Technologies Used
- Python
- Pandas
- NumPy
- Scikit-Learn
- Matplotlib
- m2cgen
- Arduino IDE
- ESP32 DevKitC V4

# Author
Adhitya Noer Effendi 235150307111024
