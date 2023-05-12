import matplotlib.pyplot as plt 
import numpy as np 

x = np.linspace(0, 5, 20)
print(x)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, np.sin(x), marker='o', color ='r', linestyle 
='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y = sen(x)")

plt.title("Función senoidal")
plt.show()


fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot (x, np.cos(x), marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y = cos(x)")

plt.title("Función cosenoidal")
plt.show()


x = np.linspace (0, 50, 50)
fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot (x, np.log(x), marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y = log(x)")

plt.title("Función logaritmo")
plt.show()


fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot (x, x, marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y = x")

plt.title("Función lineal")
plt.show()


x = range(-20,20)
y = [v*v for v in x]
plt.plot(x, y)
plt.show()


x = range(0,20)
y = [2**v for v in x]
plt.plot(x, y)
plt.show()