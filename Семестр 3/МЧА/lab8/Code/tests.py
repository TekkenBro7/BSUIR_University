import sympy

z = sympy.symbols("z")

f_1 = sympy.sin(z**3)
left_border_1 = 1
right_border_1 = 4
middle_dot_1 = 2.5
int_precised_1 = 0.204284

f_2 = sympy.cos(z)
left_border_2 = 4
right_border_2 = 8
middle_dot_2 = 6
int_precised_2 = 1.7462

f_3 = sympy.sqrt(sympy.tan(z))
left_border_3 = 0
right_border_3 = 1.5
middle_dot_3 = 0.75
int_precised_3 = 1.6893633

f_4 = sympy.sinh(1 / z)
left_border_4 = 1
right_border_4 = 2
middle_dot_4 = 1.5
int_precised_4 = 0.7576327

f_5 = z**4 - 3
left_border_5 = 0
right_border_5 = 4
middle_dot_5 = 2
int_precised_5 = 192.8
