import pandas as pd

with open("testdata.in", mode="r") as f:
    contents = f.read()
    data = [entry.split("#") for entry in contents.split("\n")]

df = pd.DataFrame(data, columns=["Judul", "Artist", "View"])
df = df.astype({'View':'int'})

df.sort_values(by=['View', 'Judul'], ascending=[False, True], inplace=True)

for i in range(len(df)):
    judul = df.loc[i, 'Judul']
    artist = df.loc[i, 'Artist']
    view = df.loc[i, 'View']
    print("{} by {} - {}".format(judul, artist, view))