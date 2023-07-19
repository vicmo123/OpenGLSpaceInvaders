//
// Created by jlidou on 22/12/22.
//

#ifndef MONPROJETSDL_MATH_H
#define MONPROJETSDL_MATH_H

#include <random>

namespace hmg{ //help maths game
    struct vect2f {
        float x, y;

        static vect2f zero(){
            return vect2f{0.0f, 0.0f};
        }


    };

    struct Vector2D {
        float x;
        float y;

        Vector2D() : x(0), y(0) {

        }

        static Vector2D zero(){
            return Vector2D{0.0f, 0.0f};
        }

        Vector2D(float x_, float y_) : x(x_), y(y_) {

        }

        void Set(float x_, float y_) {
            x = x_;
            y = y_;
        }

        void Set(Vector2D& v) {
            this->x = v.x;
            this->y = v.y;
        }

        Vector2D *const Get() const {
            return new Vector2D(this->x, this->y);
        }

        float GetMagnitude() {
            return sqrt(x*x + y*y);
        }

        float sqrMagnitude(){
            return x * x + y * y;
        }

        void Add(hmg::Vector2D * v) {
            x += v->x;
            y += v->y;
        }

        void Add(float x_, float y_) {
            x += x_;
            y += y_;
        }

        Vector2D Add(Vector2D& v1, Vector2D& v2) {
            return Vector2D(v1.x + v2.x, v1.y + v2.y);
        }

        void Sub(Vector2D& v) {
            x -= v.x;
            y -= v.y;
        }

        static Vector2D SubReturn(Vector2D& v1, Vector2D v2) {
            v1.x -= v2.x;
            v1.y -= v2.y;

            return v1;
        }

        void Sub(float x_, float y_) {
            x -= x_;
            y -= y_;
        }

        static Vector2D Sub(Vector2D& v1, Vector2D& v2) {
            return Vector2D(v1.x - v2.x, v1.y - v2.y);
        }

        void Mult(float scalar) {
            x *= scalar;
            y *= scalar;
        }

        Vector2D Mult(Vector2D& v, float scalar) {
            return Vector2D(scalar * v.x, scalar * v.y);
        }

        void Mult(Vector2D& v) {
            x *= v.x;
            y *= v.y;
        }

        Vector2D Mult(Vector2D& v1, Vector2D& v2) {
            return Vector2D(v1.x * v2.x, v1.y * v2.y);
        }

        void Div(float scalar) {
            x /= scalar;
            y /= scalar;
        }

        Vector2D Div(Vector2D& v, float scalar) {
            return Vector2D(v.x / scalar, v.y / scalar);
        }

        void Div(Vector2D& v) {
            x /= v.x;
            y /= v.y;
        }

        Vector2D Div(Vector2D& v1, Vector2D& v2) {
            return Vector2D(v1.x / v2.x, v1.y / v2.y);
        }

        float Distance(Vector2D& v) {
            float dx = x - v.x;
            float dy = y - v.y;
            return sqrt((dx * dx) + (dy * dy));
        }

        static float Distance(Vector2D& v1, Vector2D& v2) {
            float dx = v1.x - v2.x;
            float dy = v1.y - v2.y;
            return sqrt((dx * dx) + (dy * dy));
        }

        float Dot(Vector2D& v) {
            return (x * v.x) + (y * v.y);
        }

        float Dot(float x_, float y_) {
            return (x * x_) + (y * y_);
        }

        float Dot(Vector2D& v1, Vector2D& v2) {
            return (v1.x * v2.x) + (v1.y * v2.y);
        }

        void Normalize() {
            float mag = GetMagnitude();
            if (mag != 0 && mag != 1) {
                Div(mag);
            }
        }

        Vector2D* normalized(){
            Vector2D* v = new Vector2D(x, y);
            v->Normalize();
            return v;
        }

        void Limit(float max) {

            if (sqrMagnitude() > max * max)
            {
                Normalize();
                Mult(max);
            }
        }

        float Heading() {
            return atan2(-y, x);
        }
    };

    struct bounds2D{
        float width,height;
    };

    struct randomNumber{
        static int generateNumber(int minVal, int maxVal){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(minVal, maxVal);

            return dist(mt);
        }

        static float generateNumberF(float minVal, float maxVal){

            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(minVal, maxVal);

            return dist(mt);
        }
    };
}
#endif //MONPROJETSDL_MATH_H
