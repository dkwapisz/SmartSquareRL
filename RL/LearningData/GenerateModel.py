import keras
import tensorflow as tf
from tensorflow.python.keras import Sequential
from tensorflow.python.keras.layers import Conv2D, Flatten, Dense, MaxPooling2D
from tensorflow.python.keras.losses import Huber

model_num = 7

model = Sequential()
model.add(Conv2D(32, (3, 3), strides=(1, 1), padding='same', input_shape=(20, 20, 5), activation='relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))

model.add(Conv2D(64, (3, 3), strides=(1, 1), padding='same', activation='relu'))

model.add(Flatten())
model.add(Dense(128, activation='relu'))
model.add(Dense(16, activation='relu'))
model.add(Dense(4))

tf.compat.v2.keras.utils.plot_model(model, show_shapes=True, to_file="model{}.png".format(model_num))
model.summary()

optimizer = keras.optimizers.Adam(lr=1e-4)
model.compile(optimizer, loss=Huber(delta=1.35))

model.save("model{}.h5".format(model_num))

