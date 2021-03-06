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
        
        reader = csv.DictReader(csvfile, delimiter='\t')
    
        for row in reader:
            Ns.append(int(row['N']))
            Flops.append(float(row['Flops'])/1.e9)

        plt.semilogx(Ns, Flops)

pp = PdfPages('RowMatrix_GFlops.pdf');

plt.axis([2, 2048, .01, 6])
plt.legend(names)
plt.title('RowMatrix RowMatrix Product Performance')
plt.xlabel('Matrix Dimension')
plt.ylabel('GFlops')
plt.xticks([2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048] , [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048])

pp.savefig()
pp.close();

