m = 1.5
a = 0.9
y0 = 0
left_border = 0
right_border = 1


def y_diff(x, y):
    return (a * (1 - y**2)) / ((1 + m) * x**2 + y**2 + 1)
