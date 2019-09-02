import matplotlib.pyplot as plt
import pandas as pd

tamanho = [10000, 30000, 50000, 70000, 90000, 110000, 130000, 150000] # tempo fixo

# ordenado (melhor caso)
data  = pd.read_csv('ordenado.csv')
plt.plot(tamanho, data['tempo'], label='Ordenado')

# ordenado inversamente (pior caso)
data  = pd.read_csv('ordenadoInversamente.csv')
plt.plot(tamanho, data['tempo'], label='Ordenado Inversamente')

# desordenado
data = pd.read_csv('desordenado.csv')
plt.plot(tamanho, data['tempo'], label='Desordenado')


plt.title('Ordenar um vetor pelo algoritmo InsertionSort')
plt.xlabel('Tamanho do vetor (elementos)')
plt.ylabel('Tempo ordenação (segundos)')
plt.ylim(ymin=0)
plt.legend()
plt.grid(True)

plt.show()
