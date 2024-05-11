import matplotlib.pyplot as plt
import re

def read_data(filename):
    data = None
    with open(filename, "r") as f:
        data = f.read()
    return data   

def parse_values(data):
    iterations = list(map(int,re.findall("Iterations: (\d+)", data)))   
    time = list(map(int,re.findall("Time elapsed: (\d+)", data)))
    return iterations, time

iterations_smt1, time_smt1 = parse_values(read_data("output/smt/smt_iter1.txt"))
iterations_smt2, time_smt2 = parse_values(read_data("output/smt/smt_iter2.txt"))
iterations_smt3, time_smt3 = parse_values(read_data("output/smt/smt_iter3.txt"))
iterations_smt4, time_smt4 = parse_values(read_data("output/smt/smt_iter4.txt"))
iterations_smt5, time_smt5 = parse_values(read_data("output/smt/smt_iter5.txt"))
iterations_smt6, time_smt6 = parse_values(read_data("output/smt/smt_iter6.txt"))
iterations_smt7, time_smt7 = parse_values(read_data("output/smt/smt_iter7.txt"))
iterations_smt8, time_smt8 = parse_values(read_data("output/smt/smt_iter8.txt"))
iterations_smt9, time_smt9 = parse_values(read_data("output/smt/smt_iter9.txt"))
iterations_smt10, time_smt10 = parse_values(read_data("output/smt/smt_iter10.txt"))
iterations_smt11, time_smt11 = parse_values(read_data("output/smt/smt_iter11.txt"))
iterations_smt12, time_smt12 = parse_values(read_data("output/smt/smt_iter12.txt"))

plt.plot(iterations_smt1, time_smt1)
plt.plot(iterations_smt2, time_smt2)
plt.plot(iterations_smt3, time_smt3)
plt.plot(iterations_smt4, time_smt4)
plt.plot(iterations_smt5, time_smt5)
plt.plot(iterations_smt6, time_smt6)
plt.plot(iterations_smt7, time_smt7)
plt.plot(iterations_smt8, time_smt8)
plt.plot(iterations_smt9, time_smt9)
plt.plot(iterations_smt10, time_smt10)
plt.plot(iterations_smt11, time_smt11)
plt.plot(iterations_smt12, time_smt12)
plt.xlabel("Итерации, кол-во")
plt.ylabel("Время, нс")
plt.title("SMT")
plt.xlim(0, 600)
plt.ylim(0, 15000)
plt.grid(True)
plt.savefig("graphics/graph_smt.png")
plt.show()
