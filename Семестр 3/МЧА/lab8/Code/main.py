import numpy as np
import task
import tests
from output import solve

np.random.seed(42)

solve(task.f, task.left_border, task.right_border, task.middle_dot, task.int_precised)
# solve(tests.f_1, tests.left_border_1, tests.right_border_1, tests.middle_dot_1, tests.int_precised_1)
# solve(tests.f_2, tests.left_border_2, tests.right_border_2, tests.middle_dot_2, tests.int_precised_2)
# solve(tests.f_3, tests.left_border_3, tests.right_border_3, tests.middle_dot_3, tests.int_precised_3)
# solve(tests.f_4, tests.left_border_4, tests.right_border_4, tests.middle_dot_4, tests.int_precised_4)
# solve(tests.f_5, tests.left_border_5, tests.right_border_5, tests.middle_dot_5, tests.int_precised_5)
