import matplotlib.pyplot as plt
import seaborn as sns


def Top_Affected_Countries(terror):
    plt.subplots(figsize=(19, 7))
    sns.barplot(terror['Country'].value_counts()[:15].index,
                terror['Country'].value_counts()[:15].values,
                palette='inferno')
    plt.title('Top Effected Country')
    plt.show()


def Attacks_vs_Killed(terror):
    Terror_Count = terror['Country'].value_counts()[:15].to_frame()
    Terror_Count.columns = ['Attacks']
    Kill_Count = terror.groupby(
        'Country')['Killed'].sum().to_frame()
    Terror_Count.merge(Kill_Count, left_index=True,
                       right_index=True, how='left').plot.bar(width=1)
    fig = plt.gcf()
    fig.set_size_inches(20, 9)
    plt.show()
