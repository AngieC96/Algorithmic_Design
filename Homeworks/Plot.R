setwd("/home/angela/Documenti/Algorithmic Design/Algorithmic_Design/Homeworks")

## Strassen's Algorithm

T <- as.matrix(read.csv("times_Strassen.csv", head = TRUE, sep = "\t"))
n <- seq(0, 0, l = dim(T)[1])
naive <- seq(0, 0, l = dim(T)[1])
strassen <- seq(0, 0, l = dim(T)[1])
strassen_bst <- seq(0, 0, l = dim(T)[1])
for(i in 1:dim(T)[1]) {
	n[i] <- T[i, 1]
	naive[i] <- T[i, 2]
	strassen[i] <- T[i, 3]
	strassen_bst[i] <- T[i, 4]
}

naive[2] <- 0.000001
strassen[2] <- 0.000001
strassen[3] <- 0.000001
strassen_bst[2] <- 0.000001
strassen_bst[3] <- 0.000001

maxylim <- max(as.numeric(naive), as.numeric(strassen), as.numeric(strassen_bst))
#png(width=1366, height=810, pointsize=15, file="strassen.png")
png(width=8, height=6, units = "cm", res = 300, pointsize = 10, file="strassen.png")
par(mar=c(3,2.5,1,1), mgp=c(1.5, 0.5, 0)) # mar=c(bottom, left, top, right), c(axis title, axis labels, axis line). default: mar=c(5, 4, 4, 2) + 0.1, mgp=c(3, 1, 0)
plot(log(n), naive, type="p", pch = 21, xaxt = "n", xlab = "Dimension", ylab = "Time [s]", col = 2, bg = 2, cex.axis=.75, cex.lab=.75)
lines(log(n), naive, col = 2)
points(log(n), strassen, pch = 21, col = 3, bg=3)
lines(log(n), strassen, col = 3)
points(log(n), strassen_bst, pch = 21, col = 4, bg=4)
lines(log(n), strassen_bst, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = log(n), labels = n, cex.axis = .75)
legend(x = 0, y = maxylim, legend=c("Naive alg.", "Strassen alg.", "Strassen alg. best"), col = c(2, 3, 4), lty=1, cex=.7)
dev.off()


## Binary Heap

T <- as.matrix(read.csv("times_delete_min.csv", head = TRUE, sep = "\t"))
n <- seq(0, 0, l = dim(T)[1])
heap <- seq(0, 0, l = dim(T)[1])
array <- seq(0, 0, l = dim(T)[1])
for(i in 1:dim(T)[1]) {
	n[i] <- T[i, 1]
	heap[i] <- T[i, 2]
	array[i] <- T[i, 3]
}

maxylim <- max(as.numeric(array), as.numeric(heap))
#png(width=1366, height=810, pointsize=15, file="heap.png"))
png(width=8, height=6, units = "cm", res = 300, pointsize = 10, file="heap.png")
par(mar=c(3,2.5,1,1), mgp=c(1.5, 0.5, 0)) # mar=c(bottom, left, top, right), c(axis title, axis labels, axis line). default: mar=c(5, 4, 4, 2) + 0.1, mgp=c(3, 1, 0)
plot(n, array, type="p", pch = 21, xaxt = "n", xlab = "Dimension", ylab = "Time [s]", col = 3, bg = 3, cex.axis=.75, cex.lab=.75)
lines(n, array, col = 3)
points(n, heap, pch = 21, col = 4, bg=4)
lines(n, heap, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = n, labels = n, cex.axis = .75)
legend(x = 0, y = maxylim, legend=c("Array", "Heap"), col = c(3, 4), lty=1, cex=.7)
dev.off()
