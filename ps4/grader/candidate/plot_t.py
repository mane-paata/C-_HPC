import matplotlib
matplotlib.use('pdf')
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

import csv
import sys

names = []

for name in sys.argv[1:]:

    names.append(name)

    infile = name + '.txt'

    print ('plotting ' + infile)

    with open(infile, 'r') as csvfile:
        Ns = []
        Flops = []
        Time = []
        
        reader = csv.DictReader(csvfile, delimiter='\t')
    
        for row in reader:
            Ns.append(int(row['N']))
            Flops.append(float(row['Flops'])/1.e9)
            Time.append(float(row['Time'])/1.e3)

        plt.semilogx(Ns, Time)

pp = PdfPages('RowMatrix_Time.pdf');

plt.axis([2, 2048, 0, 400])
plt.legend(names)
plt.title('RowMatrix RowMatrix Product Performance')
plt.xlabel('Matrix Dimension')
plt.ylabel('Time (seconds)')
plt.xticks([2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048] , [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048])

pp.savefig()
pp.close();

