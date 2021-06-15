import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd


def Number_of_Terrorist_Activites_By_Region(terror):
    plt.subplots(figsize=(15, 6))
    sns.countplot('Region', data=terror,
                  order=terror['Region'].value_counts().index)
    plt.xticks(rotation=90)
    plt.title('Number of Terrorist Activites By Region')
    plt.show()


def Trend_in_Terrorist_Activities(terror):
    terror_region = pd.crosstab(terror.Year, terror.Region)
    terror_region.plot()
    fig = plt.gcf()
    fig.set_size_inches(20, 8)
    plt.show()


def AttackType_vs_Region(terror):
    pd.crosstab(terror.Region, terror.AttackType).plot.barh(
        stacked=True, width=1, color=sns.color_palette('RdYlGn', 9))
    fig = plt.gcf()
    fig.set_size_inches(13, 9)
    plt.show()
