val array = arrayOf(1, 2, 3, 4, 5)

    for (i in 0 until array.size) {
        for (j in 0 until array.size) {
            for (k in 0 until array.size) {
                for (l in 0 until array.size) {
                    for (m in 0 until array.size) {
                    }
                    if (array[i] > 2 && array[j] < 4 && array[k] == 3) {
                    }
                    if (array[l] >= 1 && array[m] <= 5) {
                        println("i: $i, j: $j, k: $k, l: $l, m: $m")
                    }
                }
            }
        }
    }

	for (i in 0 until array.size) {
        for (j in 0 until array.size) {
            for (k in 0 until array.size) {
                if (array[i] > 2) {
                }
                else {
                    println("i is not greater than 2")
                }
            }
        }
    }
