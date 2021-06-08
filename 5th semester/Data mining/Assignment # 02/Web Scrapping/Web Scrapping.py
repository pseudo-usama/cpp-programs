# Requirments to run this code
#   selenium is installed
#   Chrome webdriver is downloaded & added to the path

# Note: The developers of this website continuously updating this website.
#       So their is a chance that an error occur. Or the output CSV file is awkward

from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains
import csv


def fetch_data():
    with open('Scraped.csv', 'a', newline='') as f:
        writer = csv.DictWriter(f, ['Date & Time', 'Temperature', 'Clouds', 'Humidity', 'Barometer', 'Wind', 'Wind Direction'])
        
        for i in range(500):
            try:
                elem = driver.find_element_by_id('ws_' + str(i))
            except:
                break

            # Hovering the div
            ActionChains(driver).move_to_element(elem).perform()

            # Now fetching the data
            time_date = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[1]').get_attribute('innerHTML')
            temp = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[3]/div[2]/div[1]').get_attribute('innerHTML')
            clouds = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[3]/div[2]/div[2]').get_attribute('innerHTML')[:-1:]
            humidity = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[4]/div[1]').get_attribute('innerHTML')[38:42:]
            barometer = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[4]/div[2]').get_attribute('innerHTML')[39::]
            wind = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[5]/div[2]').get_attribute('innerHTML')[34::]
            wind_direction = driver.find_element_by_xpath('/html/body/div[1]/div[7]/article/section[1]/div[2]/div[4]/div[5]/div[1]').get_attribute('innerHTML')

            # Saving data
            writer.writerow({'Date & Time': time_date, 'Temperature': temp, 'Clouds': clouds, 'Humidity': humidity, 'Barometer': barometer, 'Wind': wind, 'Wind Direction': wind_direction})

            # Printing data
            # print('Data & Time    : ' + time_date)
            # print("Temperature    : " + temp)
            # print("Clouds         : " + clouds)
            # print("Humidity       : " + humidity)
            # print('Barometer      : ' + barometer)
            # print('Wind           : ' + wind)
            # print('Wind Direction : ' + wind_direction)
            # print()

            
with open ('Scraped.csv', 'w', newline='') as f:
    writer = csv.DictWriter(f, ['Date & Time', 'Temperature', 'Clouds', 'Humidity', 'Barometer', 'Wind', 'Wind Direction'])
    writer.writeheader()

driver = webdriver.Chrome()

for i in range(2015, 2019):
    for j in range(1, 13):
        driver.get('https://www.timeanddate.com/weather/pakistan/lahore/historic?month=' + str(j) + '&year=' + str(i))
        fetch_data()
