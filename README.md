# Printer_3D_Predictive_Maintainence

This is the repository for the predictive maintainence task of classifing 3D-prints. The 3D-prints are devided into two classes: Dash and noDash
For every class 3 versions of prints have been created and recorded. Different approaches have been evaluated. One way is to make plateau within the electrical impulse and count/analyze how many datapoints are belonging to each plateau. The other approach is to consider the recordings in a temporal aspect. The Timeseries-method of making windows or temporal subsets is used. For both methods only the "BUS" feature is used, because it represents the current pulse of the 3D-printer.

# Exploration in data

In **`exploration_printer3D_data.ipynb`** the recordings have been analyzed and displayed with Matplotlib. In total all recordings whether Dash or noDash are presented in the following image:

![CurrentPulses](current_impulse_all.png)