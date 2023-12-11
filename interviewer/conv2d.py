import numpy as np

def conv2d(input_data, kernel):
	input_height, input_width = input_data.shape
	kernel_height, kernel_width = kernel.shape

	output_height = input_height - kernel_height + 1
	output_width = input_width - kernel_width + 1

	conv_result = np.zeros((output_height, output_width))

	for i in range(output_height):
		for j in range(output_width):
			conv_result[i, j] = np.sum(input_data[i:i + kernel_height, j:j+kernel_width] * kernel)
	return conv_result

def conv2d_2(input_data, kernel):
	input_height, input_width = input_data.shape 
	kernel_height, kernel_width = kernel.shape 

	output_height = input_height - kernel_height + 1
	output_width = input_width - kernel_width + 1

	conv_result = np.zeros((output_height, output_width))

	for i in range(output_height):
		for j in range(output_width):
			conv_result[i, j] = np.sum(input_data[i:i+kernel_height, j:j+kernel_width] * kernel)
	return conv_result

input_data = np.array([[1,2,3,4,5],
					   [6,7,8,9,10],
					   [11,12,13,14,15]])

kernel = np.array([[1, 0], [0, 1]])
result = conv2d(input_data, kernel)
print(result)

result = conv2d_2(input_data, kernel)
print(result)
