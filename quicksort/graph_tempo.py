import matplotlib.pyplot as plt
import pandas as pd

tamanho = [10000, 30000, 50000, 70000, 90000, 110000, 130000, 150000] # tempo fixo

# ordenado (melhor caso)
data  = pd.read_csv('ordenado.csv')
plt.plot(tamanho, data['tempo'], label='Ordenado', color='green', linestyle='--')

# ordenado inversamente (pior caso)
data  = pd.read_csv('ordenadoInversamente.csv')
plt.plot(tamanho, data['tempo'], label='Ordenado Inversamente', color='red', linestyle='-')

# desordenado
data = pd.read_csv('desordenado.csv')
plt.plot(tamanho, data['tempo'], label='Desordenado', color='blue', linestyle=':')


plt.title('Ordenar um vetor pelo algoritmo QuickSort')
plt.xlabel('Tamanho do vetor (elementos)')
plt.ylabel('Tempo ordenação (segundos)')
#plt.ylim(ymin=-1)
plt.xlim(xmin=10000)
plt.legend()
plt.grid(True)
plt.savefig('GraficoTn.png')


plt.show()
