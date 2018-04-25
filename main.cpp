#include <bits/stdc++.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unistd.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "uniform mat4 transform;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0, 0.0, 0.0, 1.0);\n"
    "}\n\0";

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // float vertices[] = {
    //     -0.05f+0.25f, -0.05f+0.25f, 0.0f, // left  
    //      0.05f+0.25f, -0.05f+0.25f, 0.0f, // right 
    //      0.0f+0.25f,  0.05f+0.25f, 0.0f, // top   
    // };

float vertices[] = {
    0.25f, 0.25f, 0.25f,
     0.5f, 0.25f, 0.25f,
     0.5f,  0.5f, 0.25f,
     0.5f,  0.5f, 0.25f,
    0.25f,  0.5f, 0.25f,
    0.25f, 0.25f, 0.25f,

    0.25f, 0.25f,  0.5f,
     0.5f, 0.25f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    0.25f,  0.5f,  0.5f,
    0.25f, 0.25f,  0.5f,

    0.25f,  0.5f,  0.5f,
    0.25f,  0.5f, 0.25f,
    0.25f, 0.25f, 0.25f,
    0.25f, 0.25f, 0.25f,
    0.25f, 0.25f,  0.5f,
    0.25f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, 0.25f,
     0.5f, 0.25f, 0.25f,
     0.5f, 0.25f, 0.25f,
     0.5f, 0.25f,  0.5f,
     0.5f,  0.5f,  0.5f,

    0.25f, 0.25f, 0.25f,
     0.5f, 0.25f, 0.25f,
     0.5f, 0.25f,  0.5f,
     0.5f, 0.25f,  0.5f,
    0.25f, 0.25f,  0.5f,
    0.25f, 0.25f, 0.25f,

    0.25f,  0.5f, 0.25f,
     0.5f,  0.5f, 0.25f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    0.25f,  0.5f,  0.5f,
    0.25f,  0.5f, 0.25f,
};

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);

    // 3d matrices
    glm::mat4 model, view, projection;
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float) SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);

    // triangle initial position
    glm::vec3 trianglePosition(0.25f, 0.25f, 0.0f);

    // triangle initial speed vector
    glm::vec3 triangleSpeed(-200.0f, 0.0f, 0.0f);

    // universal attraction law vector
    glm::vec3 fVector;

    // triangle transform matrix (first move it to triangle position)
    glm::mat4 triangleTransform;
    // triangleTransform = glm::translate(triangleTransform, trianglePosition);

    // get transform uniform id
    int transformLocation = glGetUniformLocation(shaderProgram, "transform");

    // configure 3d uniforms
    int modelLocation = glGetUniformLocation(shaderProgram, "model");
    int viewLocation = glGetUniformLocation(shaderProgram, "view");
    int projectionLocation = glGetUniformLocation(shaderProgram, "projection");

    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

    // mass of the fake origin planet
    int originMass = 1;

    // triangle mass (planet)
    int triangleMass = 1;

    // moving step
    float step = 0.0001f;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        usleep(5000);

        // float currentTime = (float)glfwGetTime();
        float r = glm::distance(glm::vec3(0.0f, 0.0f, 0.0f), trianglePosition);
        float f = (float)(originMass*triangleMass)/(r*r); // (universal force) newton rocks!
        fVector = trianglePosition * (-1.0f) * f * (1.0f/r); // F vector
        triangleSpeed = (fVector + triangleSpeed);
        trianglePosition = trianglePosition+triangleSpeed*step;

        triangleTransform = glm::translate(triangleTransform, triangleSpeed*step);

        // configure 3d uniforms
        int modelLocation = glGetUniformLocation(shaderProgram, "model");
        int viewLocation = glGetUniformLocation(shaderProgram, "view");
        int projectionLocation = glGetUniformLocation(shaderProgram, "projection");

        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));


        // fVector = trianglePosition + glm::scale(fVector, glm::vec3(f/r, f/r, f/r)); // scale vector
        // trianglePosition = glm::translate(trianglePosition, glm::vec3(currentTime*0.01f, 0.0f, 0.0f));

        glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(triangleTransform));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();

    return 0;
}