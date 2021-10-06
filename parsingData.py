from math import log
import matplotlib.pyplot as plt


def draw_line(path):
    fig, (plotTime, plotComp) = plt.subplots(2)
    plotTime.set(xlabel='log2(numElements)', ylabel='log2(time)')
    plotTime.grid()
    plotComp.set(xlabel='log2(numElements)', ylabel='log2(numComperes)')
    plotComp.grid()

    with open(path, 'r') as f:
        name = path.split('/')[2][:-4]
        fig.suptitle(name, fontsize=16)
        f.readline()
        data = list(map(lambda x: list(map(float, x.split(','))), f.readlines()))
        # xVals = [log(line[0], 2) for line in data]
        xVals = [line[0] for line in data]

        plotTime.plot(xVals, [line[1] for line in data], label='selectionSort', color='blue')
        plotTime.plot(xVals, [line[3] for line in data], label='insertionSort', color='red')
        plotComp.plot(xVals, [line[2] for line in data], color='blue')
        plotComp.plot(xVals, [line[4] for line in data], color='red')
        plotTime.plot(xVals, [line[5] for line in data], label='shellSort', color='green')
        plotComp.plot(xVals, [line[6] for line in data], color='green')
        plotTime.plot(xVals, [line[7] for line in data], label='mergeSort', color='purple')
        plotComp.plot(xVals, [line[8] for line in data], color='purple')

    fig.legend()
    plotTime.set_xscale('log')
    plotComp.set_xscale('log')
    plotTime.set_yscale('log')
    plotComp.set_yscale('log')

    plt.tight_layout()
    # plt.show()
    savePath = './img/' + name + '.png'
    fig.savefig(savePath)


if __name__ == '__main__':
    draw_line('./src/randomArrays.csv')
    draw_line('./src/randomArrays123.csv')
    draw_line('./src/sortedArrays.csv')
    draw_line('./src/reversedArrays.csv')
