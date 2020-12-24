# Gillespie
An implementation of the gillespie algorithm to simulate SEIR epidemics.

Parameters (Max number of steps, Population, gamma, beda ny) can be modified in the file "InputSellke.txt" in the folder "Output file"

It writes a .csv file with five columns.

1. the number of Suscettible individuals
2. the number of Exposed individuals
3. the number of Infected individuals
4. the number of Recovered individuals
5. the time line

Each row indicates the status of the epidemic at the time indicated in the fifth column.

In the Folder Output File you can find an R script to make a quick study of the .csv file 