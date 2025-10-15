import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("Base.csv")
df = df.dropna(axis=1, how='all')
df_t = df.set_index('n').T
df_t.index = df_t.index.astype(int)

df_t.plot(marker='o')
plt.xlabel('Número de elementos (n)')
plt.ylabel('Tiempo (segundos)')
plt.title('Comparación de tiempos de ejecución por algoritmo')

plt.grid(True)
plt.show()
