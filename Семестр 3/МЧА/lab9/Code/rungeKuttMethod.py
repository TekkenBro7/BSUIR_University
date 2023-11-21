def rungeKutt(xdot, N, y0, y_diff):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        K1 = h * y_diff(x, y)
        K2 = h * y_diff(x + h / 2, y + K1 / 2)
        K3 = h * y_diff(x + h / 2, y + K2 / 2)
        K4 = h * y_diff(x + h, y + K3)
        ydots += [y + 1 / 6 * (K1 + 2 * K2 + 2 * K3 + K4)]
    return ydots
