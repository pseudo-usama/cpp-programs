import sys
import pandas as pd
from sklearn import preprocessing


# It removes the empty rows
def remove_empty_rows(dataset):
    arr = []

    for index, row in dataset.iterrows():
        if row['Clouds'] == 'No weather data availabl':
            arr.append(index)

    dataset = dataset.drop(dataset.index[arr])

    return dataset


# Preprocess Temperature Column
def preprocess_temperature(temperature):
    # Minimum & Maximum for int
    mini = sys.maxsize
    maxi = -sys.maxsize

    # In Temperature column there are two temperatures. So we take average for those
    # And we also find mini & maxi
    for index, row in temperature.iterrows():
        temp = row['Temperature'][:-3:].split('/')
        row['Temperature'] = (int(temp[0], 10) + int(temp[1], 10)) / 2

        if row['Temperature'] < mini:
            mini = row['Temperature']
        elif row['Temperature'] > maxi:
            maxi = row['Temperature']

    # Now we transform temperature in 0-1 range.
    # Then we set temperature as L(Low), M(Medium), H(High)
    for index, row in temperature.iterrows():
        temp = (row['Temperature'] - mini) / (maxi - mini)

        if temp < 0.26:
            row['Temperature'] = 'L'
        elif temp < 0.76:
            row['Temperature'] = 'M'
        else:
            row['Temperature'] = 'H'

    return temperature


# Preprocess Humidity Column
def preprocess_humidity(humidity):
    # Humidity is in percentage. So we convert it as L(Low), M(Mild), H(High)
    for index, row in humidity.iterrows():
        hum = int(row['Humidity'][:-1])

        if hum < 26:
            row['Humidity'] = 'L'
        elif hum < 76:
            row['Humidity'] = 'M'
        else:
            row['Humidity'] = 'H'

    return humidity


# Preprocess Clouds Column
def preprocess_clouds(clouds):
    # arr = ['cloud', 'fog', 'clear', 'sunny', 'haze', 'rain', 'cool', 'mild', 'chilly', 'smoke', 'duststorm', 'warm', 'hot', 'thunderstorms']
    # for index, row in clouds.iterrows():
    #     if len([i for i in arr if i in row['Clouds'].lower()]) == 0:
    #         print(index, row['Clouds'])

    for index, row in clouds.iterrows():
        # if 'rain' in row['Clouds'].lower():
        #     row['Clouds'] = 'Rain'
        #
        # elif 'cloud' in row['Clouds'].lower():
        #     row['Clouds'] = 'Clouds'
        #
        # elif 'clear' in row['Clouds'].lower() or 'sunny' in row['Clouds'].lower():
        #     row['Clouds'] = 'Clear'
        #
        # elif 'duststorm' in row['Clouds'].lower() or 'thunderstorms' in row['Clouds'].lower():
        #     row['Clouds'] = 'Storm'
        #
        # elif 'fog' in row['Clouds'].lower():
        #     row['Clouds'] = 'Fog'
        #
        # elif 'mild' in row['Clouds'].lower():
        #     row['Clouds'] = 'Mild'
        #
        # elif 'smoke' in row['Clouds'].lower() or 'haze' in row['Clouds'].lower():
        #     row['Clouds'] = 'Haze'
        #
        # elif 'warm' in row['Clouds'].lower() or 'hot' in row['Clouds'].lower():
        #     row['Clouds'] = 'Hot'
        #
        # elif 'chilly' in row['Clouds'].lower() or 'cool' in row['Clouds'].lower():
        #     row['Clouds'] = 'Cool'
        #
        # else:
        #     print(row['Clouds'])

        if 'clear' in row['Clouds'].lower():
            row['Clouds'] = 'Clear'
        else:
            row['Clouds'] = 'Not Clear'

    return clouds


# Preprocess Barometer Column
def preprocess_barometer(barometer):
    # Setting maximum & minimum passible values for int
    mini = sys.maxsize
    maxi = -sys.maxsize
    
    # Here we remove 'mbar' from data and also find mini & maxi
    for index, row in barometer.iterrows():
        row['Barometer'] = int(row['Barometer'].replace('mbar', '').strip())

        if row['Barometer'] < mini:
            mini = row['Barometer']
        elif row['Barometer'] > maxi:
            maxi = row['Barometer']

    # First we transform our data in 0-1 range. Then convert this data in L(Low), M(Medium), H(High)
    for index, row in barometer.iterrows():
        temp = (row['Barometer'] - mini) / (maxi - mini)

        if temp < 0.26:
            row['Barometer'] = 'L'
        elif temp < 0.76:
            row['Barometer'] = 'M'
        else:
            row['Barometer'] = 'H'

    return barometer


# Preprocess the Wind Column
def preprocess_wind(wind):
    # Minimum & Maximum for int
    mini = sys.maxsize
    maxi = -sys.maxsize

    # First we find mini & maxi and remove km/h
    for index, row in wind.iterrows():
        row['Wind'] = int(row['Wind'].replace('km/h', '').strip())

        if row['Wind'] < mini:
            mini = row['Wind']
        elif row['Wind'] > maxi:
            maxi = row['Wind']

    # Now we transform our data in 0-1 range
    # After that we categorize wind in S(Slow), F(Fast)
    for index, row in wind.iterrows():
        temp = (row['Wind'] - mini) / (maxi - mini)

        if temp < 0.26:
            row['Wind'] = 'S'
        elif temp < 0.76:
            row['Wind'] = 'M'
        else:
            row['Wind'] = 'F'

    return wind


# Encodes DataFrame so that can be useable in Decision Tree
def sklearn_preprocessing(df):
    le = preprocessing.LabelEncoder()

    for i in range(1, 7):
        df.iloc[:, i] = le.fit_transform(df.iloc[:, i])

    return df


file = pd.read_csv('Scraped.csv', encoding='ANSI')              # Reading CSV file

file = remove_empty_rows(file)                                  # Remove the empty rows


file.iloc[:, 1:2] = preprocess_temperature(file.iloc[:, 1:2])   # Preprocess Temperature Column

file.iloc[:, 3:4] = preprocess_humidity(file.iloc[:, 3:4])      # Preprocess Humidity Column

file.iloc[:, 2:3] = preprocess_clouds(file.iloc[:, 2:3])        # Preprocess Clouds Column

file.iloc[:, 4:5] = preprocess_barometer(file.iloc[:, 4:5])     # Preprocess Barometer

file.iloc[:, 5:6] = preprocess_wind(file.iloc[:, 5:6])          # Preprocess Wind Column

sklearn_preprocessing(file)

file = file[['Date & Time', 'Temperature', 'Humidity', 'Barometer', 'Wind', 'Wind Direction', 'Clouds']]

file.to_csv('Pre-processed.csv', sep=',', index=False, encoding='ANSI')          # Saving CSV file
