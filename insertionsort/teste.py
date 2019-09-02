import matplotlib.pyplot as plt

plt.title('Tempo necessário para ordenar um vetor')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo ordenação (seg)')


tamanho = [10000, 30000, 50000, 70000, 90000, 110000, 130000, 150000] # tempo fixo

# ordenado
tempo = [0.000221, 0.000558, 0.001038, 0.001124, 0.001334, 0.001644, 0.002037, 0.002230] # y
plt.plot(tamanho, tempo, label='Ordenado')

# ordenado inversamente
tempo = [0.216803, 1.192410, 3.440201, 6.706852, 10.839969, 16.256894, 22.608324, 31.399793]
plt.plot(tamanho, tempo, label='Ordenado Inversamente')

plt.show()
