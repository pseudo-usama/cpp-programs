import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd


def Number_of_Terrorist_Activites_By_City(terror, City_Range=10):
    plt.subplots(figsize=(15, 6))
    sns.countplot('City', data=terror,
                  order=terror['City'].value_counts()[1:City_Range].index)
    plt.xticks(rotation=90)
    plt.title('Number of Terrorist Activites By City')
    plt.show()


def Attacks_vs_Killed(terror, City_Range=10):
    Terror_Count = terror['City'].value_counts()[:City_Range].to_frame()
    Terror_Count.columns = ['Attacks']
    Kill_Count = terror.groupby(
        'City')['Killed'].sum().to_frame()
    Terror_Count.merge(Kill_Count, left_index=True,
                       right_index=True, how='left').plot.bar(width=1)
    fig = plt.gcf()
    fig.set_size_inches(20, 9)
    plt.show()
