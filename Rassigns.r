library(rpart)
library(caTools)
dataset= read.csv(file.choose())
dataset= dataset[,c(4,9)]
split= sample.split(dataset$MemberType, SplitRatio=0.75)
train= subset(dataset, split=TRUE)
test= subset(dataset, split=FALSE)

dtm= rpart(dataset$MemberType~., train, method="class")
rpart.plot(dtm)

p= predict(dtm, test, type="class")
p
table(test[,2], p)
#-------------------------------------------------------------------

library(e1071)
data= read.csv(file.choose())
data= data[,c(6,8,9)]
data$Outcome= factor(data$Outcome, levels = c(0,1))
s= sample.split(data$Outcome, SplitRatio = 0.60)
tr= subset(data, split=TRUE)
tt= subset(data, split= FALSE)

classifier= naiveBayes(x=tr[-3], y= tr$Outcome)
ypred= predict(classifier, newdata=tt[-3])
cm= table(tt[,3], ypred)
cm

#-------------------------------------------------------------------
x= read.csv(file.choose())
x= x[,c(1,5)]
library(lubridate)
a= ymd(x$date)
x$year = year(a)
days= as.Date(x$date)
x$day= strftime(days,'%A')

max= subset(x, 
            x$year==2018 & x$snowfall== max(snowfall))
max

