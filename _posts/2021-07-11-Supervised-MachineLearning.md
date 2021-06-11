---
layout: post
title: Supervised Learning  
description: ML introduction notes - that i may revisit     
tags: ml python
---

## ML notes  

Sometimes I am dealing with manually created decision trees or rule-based decisions 
and it is tedious to expand many if-conditions or handle every fictitious or explicit case. 
The solution seems simple, simplify things and train the machine to find an algorithm instead of building one.
My motivation also comes from the fact that I wanted to build an art project.

Even simple algorithms can be very efficient if the input is significant and the relevant features (predictors) are constructed. Learning curves have shown that with more data, accuracy increases [1]. 

Typical tasks are classification or regression.


### Model based Learning

A ML-Key Concept is Generalization. 

A model is a simplified version of the observations. 

The Model is based on training data (input pipelines -> computational graph).
 
Caveats: "Garbage in, Garbage out". 
If you associate a digital clock with bad timing, "prejudices" happens to machines, too (under- or overfitting).

Some Techniques to avoid overfitting:

- Train with more data
- Feature selection of relevant ones
- Regularization of a model (Hyperparameter) 
 


#### Simple Example

A Model could also be a formula like `y = 0.1*x`. 

In a Linear Regression x1, x2, xN would represent features, while the coefficients θ1, θ2, θn represent weights.

The input data consist of the selected features: x=Sales, y=Profit: 

```
+----+
|x |y|
+----+
|30|3|
|40|4|
|50|5|
+----+
```

If the input of sales is 100, the predicted profit is 10.  


Example by Rakesh Gopalakrishnan "Learn Data science / Machine Learning using Python (Scikit Learn)" 


### Classification  


To predict a value out of a Data-Set, we classify (a target-name based on features).

We can classify A by given B and vice versa by identfying A or B (discrete Number).

Classification-Example: train-input: emails, input: email, output: is spam or ham


### Regression 


Predicting a numerical target value that is not part of a given set, such as the price of a house, given a set of characteristics (year built, square footage, city, etc.) called predictors. 
This type of task is called regression.

Regression is a term in statistics, from Francis Galton "Regression to the Mean."

> Galton compared the height of children to that of their parents. He found that adult children are closer to average height than their parents are.


For example, if we have a data set with real numbers A through B, we can use regression algorithms to estimate a number with decimal point. B by A and vice versa.

Regression example: learn-input: emails, input: date, output: estimated number of emails


### KNN Algorithm 

The k-nearest neighbors algorithm is a supervised algorithm. Supervised because we need labeled input data for learning. The algorithm relies on distance and metrics to estimate data by feeding the algorithm with unlabeled data for classification (vote or matching the most frequent label) or regression (averaging the labels).

Example: KNN can be used for a [Recommender System](https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761).



### Logistic Regression Algorithm


I considered this algorithm for predicting sports games.
Averaging historical data, weighting the team and features like "home strong" were not enough. 
The funny thing about sports is that it is quite unpredictable with the history of team results, but combined with carefully selected features (e.g., in soccer: the players), non-specialists can get results of over 50% success in prediction, based on this article: ["A machine learning framework for sport result prediction" by Rory P.Bunker, Fadi Thabtah](https://www.sciencedirect.com/science/article/pii/S2210832717301485)



## Steps to build a ML based intelligent System:


1. Look at the big picture
2. Get a small to medium sized dataset
3. Gain insights (visualize data), extract features
4. Prepare the data for Machine Learning algorithms
5. Evaluate (No-Free-Lunch Theorem) and Select a model and train it
6. Fine-tune your model
7. Launch, monitor, and maintain your solution

( bsaed on the recommended steps of Géron, Aurélien )

### Python

#### Data-Science

When working with row and column based (tabular) data, pandas [DataFrame](https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.html#pandas.DataFrame) is the right Tool. 

Numpy brings the power of Data-Types to python in a high level syntax.


## important supervised learning algorithms:

- k-Nearest Neighbors
- Linear Regression
- Logistic Regression
- Support Vector Machines (SVMs)
- Decision Trees and Random Forests
- Neural networks


Covered in the book: "Hands-On Machine Learning" by Géron, Aurélien


### Links

- 1) [famous paper from Michele Banko and Eric Brill "Scaling to Very Very Large Corpora for Natural Language Disambiguation" 2001, Microsoft Research](https://www.aclweb.org/anthology/P01-1005.pdf)
- [Handson ML](https://github.com/ageron/handson-ml) 
- [ML Datasets - Popular datasets (from Pattern-Recognition or real Studies)](https://archive.ics.uci.edu/ml/index.php)
- [scikit-learn](https://scikit-learn.org/stable/user_guide.html)
- [tensorflow](https://www.tensorflow.org/)
- [pandas](https://pandas.pydata.org/)
- [numpy](https://numpy.org/)

