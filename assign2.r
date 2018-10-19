# Naive Bayes

# Importing the dataset
dataset = read.csv(file.choose())
dataset = dataset[,c(6,8,9)]

# Encoding the target feature as factor
dataset$Outcome = factor(dataset$Outcome, levels = c(0, 1))


#---------------Splitting the dataset-------------------
# install.packages('caTools')
library(caTools)

#set.seed(123)
split = sample.split(dataset$Outcome, SplitRatio = 0.75)
train = subset(dataset, split == TRUE)
test = subset(dataset, split == FALSE)

# install.packages('e1071')
library(e1071)
classifier = naiveBayes(x = train[-3],
                        y = train$Outcome)

# Predicting the Test set results
y_pred = predict(classifier, newdata = test[-3])

# Making the Confusion Matrix
cm = table(test[, 3], y_pred )

#display confusion matrix
cm
