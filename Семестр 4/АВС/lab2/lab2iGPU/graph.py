import matplotlib.pyplot as plt
import re

def read_data(filename):
    data = None
    with open(filename, "r") as f:
        data = f.read()
    return data   

data_smt = read_data("LOGS.txt") 
iterations = list(map(int,re.findall("Total iterations: (\d+)", data_smt)))   
time = list(map(int,re.findall("Time elapsed: (\d+)", data_smt)))  

plt.plot(iterations, time)
plt.xlabel("Итерации, кол-во")
plt.ylabel("Время, мкс")
plt.title("iGPU")
plt.xlim(0, 6600)
plt.ylim(0, 32000)
plt.grid(True)
plt.savefig("graph.png")
plt.show()
