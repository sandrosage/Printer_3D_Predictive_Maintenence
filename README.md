# Printer_3D_Predictive_Maintainence

This is the repository for the predictive maintenance task of classifying 3D prints. The 3D prints are divided into two classes: Dash and noDash
For every class 3 versions of prints have been created and recorded. Different approaches have been evaluated. One way is to make plateaus within the electrical impulse and count/analyze how many datapoints are belonging to each plateau. The other approach is to consider the recordings in a temporal aspect. The Timeseries-method of making windows or temporal subsets is used. For both methods, only the "BUS" feature is used because it represents the current pulse of the 3D printer.

# Exploration in data

In **`exploration_printer3D_data.ipynb`** the recordings have been analyzed and displayed with Matplotlib. In total all recordings whether Dash or noDash are presented in the following image:

![CurrentPulses](current_impulse_all.png)

Afterward, the data is processed with the Timeseries-method. The model at the end of the process is a Convolutional-Neural-Network with ``input_shape=(5000,1)``. The code for creating the model is the following:
``python
model = Sequential(
    [
        Conv1D(filters=32, kernel_size=3, activation='relu', input_shape=(5000,1)),
        MaxPooling1D(pool_size=4),
        Conv1D(filters=32, kernel_size=3, activation='relu'),
        MaxPooling1D(pool_size=4),
        Conv1D(filters=32, kernel_size=3, activation='relu'),
        MaxPooling1D(pool_size=4),
        
        Conv1D(filters=32, kernel_size=3, activation='relu'),
        MaxPooling1D(pool_size=4),
        Conv1D(filters=32, kernel_size=3, activation='relu'),
        MaxPooling1D(pool_size=2),
        Flatten(),
        Dense(100, activation = "relu", name = "hidden4"),
        Dense(50, activation = "relu", name = "hidden6"),
        Dense(2, activation ="softmax", name = "Output"),
    ]
)
``

The input shape means that 5000 Samples are fed into the network at once. This process imitates the Windowing. After the training and validation process the model is evaluated with a validation accuracy of ```val_accuracy: 0.9853``.