import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd


def Terrorist_Group(Terror):
    sns.barplot(Terror['Group'].value_counts()[1:15].values,
                Terror['Group'].value_counts()[1:15].index,
                palette='inferno')
    plt.xticks(rotation=90)
    fig = plt.gcf()
    fig.set_size_inches(12, 8)
    plt.title("Terrorist Group")
    plt.show()


def Terrorist_Group_Trend(Terror):
    Top_Groups = Terror[Terror['Group'].isin(
        Terror['Group'].value_counts()[1:13].index)]
    pd.crosstab(Top_Groups.Year, Top_Groups.Group).plot(
        color=sns.color_palette('Paired', 10))
    fig = plt.gcf()
    fig.set_size_inches(18, 6)
    plt.show()
