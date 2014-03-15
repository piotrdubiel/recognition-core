from nose.tools import assert_raises
import pysbp

EPS = 0.7e-2

def load_xor_network_and_classify_test():
    # given
    pysbp.init()
    pysbp.add_layer([43.259, 43.268, -66.366], [65.075, 65.101, -27.079])
    pysbp.add_layer([-29.041, 27.2972, -5.0622])

    examples = [[[0.0, 0.0], [0.0]],
                [[1.0, 0.0], [1.0]],
                [[0.0, 1.0], [1.0]],
                [[1.0, 1.0], [0.0]]]

    # when
    def check_examples(input, output):
        answer = pysbp.classify(input)
        assert abs(answer[0] - output[0]) < EPS ,\
            "Network answer for {} should be {}, not {}".format(
                input, output, answer)

    # then
    for input, output in examples:
        yield check_examples, input, output


def classify_with_random_network_test():
    # given
    pysbp.init()
    pysbp.add_layer([0.5, 0.5, 0.5])

    # when
    answer = pysbp.classify([1, 0])

    # then
    assert all(a >= 0.0 and a <= 1.0 for a in answer),\
        "Some values in {} aren't from range [0,1]".format(answer)


def classify_accepts_only_list_test():
    # given
    pysbp.init()

    # when
    def check_argument_type(exception, *args):
        assert_raises(exception, pysbp.classify, *args)
    # then
    for arg in [3, {'f': 3}, 'some string', 4.6]:
        yield check_argument_type, TypeError, arg



def train_to_solve_xor_test():
    # given
    examples = [[[0.0, 0.0], [0.0]],
                [[1.0, 0.0], [1.0]],
                [[0.0, 1.0], [1.0]],
                [[1.0, 1.0], [0.0]]]

    pysbp.init()
    pysbp.add_layer([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])
    pysbp.add_layer([0.5, 0.5, 0.5])

    # when
    for i in range(1000):
        for input, output in examples:
            pysbp.train(input, output)

    # then
    print pysbp.classify([0.0, 0.0])
    print pysbp.classify([1.0, 0.0])
