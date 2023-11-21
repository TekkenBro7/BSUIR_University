def euler(xdot, N, y0, y_diff):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        ydots += [y + h * y_diff(x, y)]
    return ydots


def modifiedEuler(xdot, N, y0, y_diff):
    ydots = [y0]
    h = xdot / N
    for i in range(N):
        x = i * h
        y = ydots[-1]
        ydots += [y + h * y_diff(x + h / 2, y + h / 2 * y_diff(x, y))]
    return ydots
