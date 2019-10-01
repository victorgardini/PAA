import matplotlib.pyplot as plt
import pandas as pd

# tamanho = [10000, 30000, 50000, 70000, 90000, 110000, 130000, 150000] # tempo fixo

# (melhor caso)
data  = pd.read_csv('melhor_caso-f.csv')
plt.plot(data['x'], data['y'], label='f(n)', color='green')

# ordenado inversamente (pior caso)
data  = pd.read_csv('melhor_caso-g.csv')
plt.plot(data['x'], data['y'], label='c.g(n)', color='red')

# tn
#data = pd.read_csv('melhor_caso-tn-nanosegundos.csv')
#plt.plot(data['x'], data['y'], label='T(n) em nanosegundos', color='blue')

plt.title('Melhor caso: f(n) e g(n)')
plt.xlabel('Tamanho do vetor (elementos)')
plt.ylabel('Quantidade de passos (pontos)')
plt.ylim(ymin=-1)
plt.xlim(xmin=10000)
plt.legend()
plt.grid(True)
plt.savefig('GraficoMelhorCasoFnGn.png')


plt.show()
