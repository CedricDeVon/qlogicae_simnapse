#include "pch.hpp"

#include <onnxruntime_cxx_api.h>

#include "main.hpp"

int main(int argc, char** argv)
{    
    Ort::Env env{ ORT_LOGGING_LEVEL_WARNING, "xor" };
    Ort::SessionOptions options;
    Ort::Session session(env, L"xor_model.onnx", options);

    std::vector<float> input_data = {
        0,0,
        0,1,
        1,0,
        1,1
    };

    std::array<int64_t, 2> input_shape = { 4, 2 };

    Ort::MemoryInfo memory_info =
        Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);

    Ort::Value input_tensor =
        Ort::Value::CreateTensor<float>(
            memory_info,
            input_data.data(),
            input_data.size(),
            input_shape.data(),
            input_shape.size());

    const char* input_names[] = { "input" };
    const char* output_names[] = { "output" };

    auto output_tensors = session.Run(
        Ort::RunOptions{ nullptr },
        input_names,
        &input_tensor,
        1,
        output_names,
        1
    );

    float* output_data = output_tensors[0].GetTensorMutableData<float>();

    std::cout << "Predictions:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << output_data[i] << "\n";
    }

    bool exit_code;
    std::cin >> exit_code;

    return 0;
}

namespace QLogicaeSimNapseSandbox
{

}

/*

- neural_network_training_data
    - epoch_number
    - weights
    - hidden_layer_biases
    - output
    - output bias
    - learning rate
    - x1, x2
    - h1, h2
    - error
    - delta_out
    - delta_h1
    - delta_h2
    - update_weights

- neural_network
    - mlp object
    - forward_press
    - train
    - print_truth_table

- multi_layered_perceptron
    - weights

*/