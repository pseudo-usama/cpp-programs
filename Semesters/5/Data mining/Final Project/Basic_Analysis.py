import matplotlib.pyplot as plt
import seaborn as sns


def Country_with_Highest_Terrorist_Attacks(Globel_Terrorism):
    print('Country with Highest Terrorist Attacks:',
          Globel_Terrorism['Country'].value_counts().index[0])


def Regions_with_Highest_Terrorist_Attacks(Globel_Terrorism):
    print('Regions with Highest Terrorist Attacks:',
          Globel_Terrorism['Region'].value_counts().index[0])


def Maximum_killed(Globel_Terrorism):
    print('Maximum people killed in an attack are:', Globel_Terrorism['Killed'].max(
    ), 'that took place in', Globel_Terrorism.loc[Globel_Terrorism['Killed'].idxmax()].Country)


def Basic_Data_Update(Globel_Terrorism):
    Country_with_Highest_Terrorist_Attacks(Globel_Terrorism)
    Regions_with_Highest_Terrorist_Attacks(Globel_Terrorism)
    Maximum_killed(Globel_Terrorism)


def Number_Of_Terrorist_Activities_Each_Year(Globel_Terrorism):
    plt.subplots(figsize=(14, 6))
    sns.countplot('Year', data=Globel_Terrorism, palette='RdYlGn_r',
                  edgecolor=sns.color_palette('dark', 7))
    plt.xticks(rotation=90)
    plt.title('Number Of Terrorist Activities Each Year')
    plt.show()


def Attacking_Methods_by_Terrorists(Globel_Terrorism):
    plt.subplots(figsize=(15, 6))
    sns.countplot('AttackType', data=Globel_Terrorism, palette='inferno',
                  order=Globel_Terrorism['AttackType'].value_counts().index)
    plt.xticks(rotation=90)
    plt.title('Attacking Methods by Terrorists')
    plt.show()


def Favorite_Targets(Globel_Terrorism):
    plt.subplots(figsize=(15, 6))
    sns.countplot(Globel_Terrorism['Target_type'], palette='inferno',
                  order=Globel_Terrorism['Target_type'].value_counts().index)
    plt.xticks(rotation=90)
    plt.title('Favorite Targets')
    plt.show()
