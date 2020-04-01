setwd("/home/angela/Documenti/Algorithmic Design/Algorithmic_Design/Homeworks")

## save the workspace
save.image("./data.RData")

## load the workspace
load("data.RData")


## Strassen's Algorithm

T <- as.matrix(read.csv("times_Strassen.csv", head = TRUE, sep = "\t"))
n1 <- seq(0, 0, l = dim(T)[1])
naive <- seq(0, 0, l = dim(T)[1])
strassen <- seq(0, 0, l = dim(T)[1])
strassen_bst <- seq(0, 0, l = dim(T)[1])
for(i in 1:dim(T)[1]) {
	n1[i] <- T[i, 1]
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
plot(log(n1), naive, type="p", pch = 21, xaxt = "n", xlab = "Dimension", ylab = "Time [s]", col = 2, bg = 2, cex.axis=.75, cex.lab=.75)
lines(log(n1), naive, col = 2)
points(log(n1), strassen, pch = 21, col = 3, bg=3)
lines(log(n1), strassen, col = 3)
points(log(n1), strassen_bst, pch = 21, col = 4, bg=4)
lines(log(n1), strassen_bst, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = log(n1), labels = n1, cex.axis = .75)
legend(x = 0, y = maxylim, legend=c("Naive alg.", "Strassen alg.", "Strassen alg. best"), col = c(2, 3, 4), lty=1, cex=.7)
dev.off()


## Binary Heap

T <- as.matrix(read.csv("times_delete_min_OLD.csv", head = TRUE, sep = "\t"))
n2 <- seq(0, 0, l = dim(T)[1])
heap <- seq(0, 0, l = dim(T)[1])
array <- seq(0, 0, l = dim(T)[1])
for(i in 1:dim(T)[1]) {
	n2[i] <- T[i, 1]
	heap[i] <- T[i, 2]
	array[i] <- T[i, 3]
}

maxylim <- max(as.numeric(array), as.numeric(heap))
#png(width=1366, height=810, pointsize=15, file="heap.png"))
png(width=8, height=6, units = "cm", res = 300, pointsize = 10, file="heap.png")
par(mar=c(3,2.5,1,1), mgp=c(1.5, 0.5, 0)) # mar=c(bottom, left, top, right), c(axis title, axis labels, axis line). default: mar=c(5, 4, 4, 2) + 0.1, mgp=c(3, 1, 0)
plot(n2, array, type="p", pch = 21, xaxt = "n", xlab = "Dimension", ylab = "Time [s]", col = 3, bg = 3, cex.axis=.75, cex.lab=.75)
lines(n2, array, col = 3)
points(n2, heap, pch = 21, col = 4, bg=4)
lines(n2, heap, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = n2, labels = n2, cex.axis = .75)
legend(x = 0, y = maxylim, legend=c("Array", "Heap"), col = c(3, 4), lty=1, cex=.7)
dev.off()

maxylim <- max(as.numeric(heap))
png(width=8, height=6, units = "cm", res = 300, pointsize = 10, file="onlyheap.png")
par(mar=c(3,2.5,1,1), mgp=c(1.5, 0.5, 0)) # mar=c(bottom, left, top, right), c(axis title, axis labels, axis line). default: mar=c(5, 4, 4, 2) + 0.1, mgp=c(3, 1, 0)
plot(n2, heap, pch = 21, col = 4, bg=4 , type="p", xaxt = "n", xlab = "Dimension", ylab = "Time [s]", cex.axis=.75, cex.lab=.75)
lines(n2, heap, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = n2, labels = n2, cex.axis = .75)
legend(x = 0, y = maxylim, legend="Heap", col = 4, lty=1, cex=.7)
dev.off()


size <- 40 # see the number of repetitions in the script script.sh!
T <- as.matrix(read.csv("times_delete_min.csv", header = FALSE, sep = "\t"))
heap <- matrix(0, nrow = length(n2), ncol = size)
array <- matrix(0, nrow = length(n2), ncol = size)
for(j in 1:size){
  for(i in 1:dim(T)[1]) {
    heap[i, j] <- T[i, 2]
    array[i, j] <- T[i, 3]
  }
}

meanheap <- seq(0, 0, l = length(n2))
meanarray <- seq(0, 0, l = length(n2))
for(i in 1:length(n2)) {
  meanarray[i] <- mean(array[i, ])
  meanheap[i] <- mean(heap[i, ])
}

maxylim <- max(as.numeric(meanheap))
png(width=8, height=6, units = "cm", res = 300, pointsize = 10, file="onlyheap.png")
par(mar=c(3,2.5,1,1), mgp=c(1.5, 0.5, 0)) # mar=c(bottom, left, top, right), c(axis title, axis labels, axis line). default: mar=c(5, 4, 4, 2) + 0.1, mgp=c(3, 1, 0)
plot(n2, meanheap, pch = 21, col = 4, bg=4 , type="p", xaxt = "n", xlab = "Dimension", ylab = "Time [s]", cex.axis=.75, cex.lab=.75)
lines(n2, meanheap, col = 4)
title("Computational time", adj = 0.5, line = 0.5, cex.main=.75)
axis(1, at = n2, labels = n2, cex.axis = .75)
legend(x = 0, y = maxylim, legend="Heap", col = 4, lty=1, cex=.7)
dev.off()
