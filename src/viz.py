import os
import pandas as pd
import matplotlib.pyplot as plt


def main():
    data_folder = "../data_output/"
    chart_folder = "../charts/"
    os.makedirs(data_folder, exist_ok=True)
    os.makedirs(chart_folder, exist_ok=True)

    for i in range(1, 11):
        rad_title = data_folder + str(i) + "rad_data.csv"

        try:
            rad_data = pd.read_csv(rad_title, names=[0, 1, 2, 3], header=None, sep=",")
            x = rad_data.iloc[:, 0]
            y_calc = rad_data.iloc[:, 1]
            y = rad_data.iloc[:, 2]
            error = rad_data.iloc[:, 3]

            plt.plot(x, y, label="sin_h")
            plt.plot(x, y_calc, label="custom_sin")
            plt.plot(x, error, label="error")
            plt.grid()
            plt.legend()
            plt.xlabel("x")
            plt.ylabel("y")
            plt.title(f"Radial Sin Approximation - {i} terms")
            plt.savefig(chart_folder + "rad_chart" + str(i) + ".png")
            plt.clf()
        except FileNotFoundError:
            print(f"File {rad_title} doesn't exist.")

        deg_title = data_folder + str(i) + "deg_data.csv"

        try:
            deg_data = pd.read_csv(deg_title, names=[0, 1, 2, 3], header=None, sep=",")
            x = deg_data.iloc[:, 0]
            y_calc = deg_data.iloc[:, 1]
            y = deg_data.iloc[:, 2]
            error = deg_data.iloc[:, 3]

            plt.plot(x, y, label="sin_h")
            plt.plot(x, y_calc, label="custom_sin")
            plt.plot(x, error, label="error")
            plt.grid()
            plt.legend()
            plt.xlabel("x")
            plt.ylabel("y")
            plt.title(f"Degree Sin Approximation - {i} terms")
            plt.savefig(chart_folder + "deg_chart" + str(i) + ".png")
            plt.clf()
        except FileNotFoundError:
            print(f"File {deg_title} doesn't exist.")


if __name__ == '__main__':
    main()

