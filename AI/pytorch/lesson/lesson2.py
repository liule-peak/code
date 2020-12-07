import torch
import numpy as np

print(torch.__version__)
print(torch.cuda.is_available())


def compute_error_for_line_given_points(w, b, points):
    totalError = 0
    for i in range(0, len(points)):
        x = points[i, 0]
        y = points[i, 1]
        totalError += (y-(w*x+b))**2
    return totalError/float(len(points))


def step_gradient(w_current, b_current, points, learningRate):
    b_gradient = 0
    w_gradient = 0
    N = float(len(points))
    for i in range(0, len(points)):
        x = points[i, 0]
        y = points[i, 1]
        b_gradient += -(2/N)*(y-((w_current*x)+b_current))
        w_gradient += -(2/N)*x*(y-((w_current*x)+b_current))
    new_b = b_current-(learningRate+b_gradient)
    new_w = w_current-(learningRate*w_gradient)
    return [new_b, new_w]


def gradient_descent_runner(points, starting_w, starting_b, learning_rate, num_iterations):
    b = starting_b
    w = starting_w
    for i in range(num_iterations):
        b, w = step_gradient(w, b,  np.array(points), learning_rate)
    return [w, b]


def run():
    points = np.genfromtxt("data.csv", delimiter=",")
    learning_rate = 0.0001
    initial_b = 0_
    initial_w = 0_
    num_iterations = 1000
    print("Starting gradient descent at b = {0},m={1},error={2}"
          .format(initial_w, initial_b, compute_error_for_line_given_points(initial_w, initial_b, points)))
    print("Running...")
    [w,b]=gradient_descent_runner((points,initial_w,initial_b,learning_rate,num_iterations))
    print("Ater {0} iteration b ={1},w={2},error={3}".format(num_iterations,m,b,compute_error_for_line_given_points(m,b,points)))

if __name__ =='__main__':
    run()