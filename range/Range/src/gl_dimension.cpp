/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   gl_dimension.cpp                                         *
 *  GROUP:  Range                                                    *
 *  TYPE:   source file (*.cpp)                                      *
 *  DATE:   6-th May 2017                                            *
 *                                                                   *
 *  DESCRIPTION: OpenGL dimension class definition                   *
 *********************************************************************/

#include "gl_arrow.h"
#include "gl_dimension.h"

void GLDimension::_init(const GLDimension *pGlDimension)
{
    if (pGlDimension)
    {

    }
}

GLDimension::GLDimension(GLWidget *glWidget,
                         double xMin,
                         double xMax,
                         double yMin,
                         double yMax,
                         double zMin,
                         double zMax)
    : GLObject(glWidget)
    , xMin(xMin)
    , xMax(xMax)
    , yMin(yMin)
    , yMax(yMax)
    , zMin(zMin)
    , zMax(zMax)
{
    this->_init();
}

GLDimension::GLDimension(const GLDimension &glDimension)
    : GLObject(glWidget)
{
    this->_init(&glDimension);
}

GLDimension::~GLDimension()
{

}

GLDimension &GLDimension::operator=(const GLDimension &glDimension)
{
    this->_init(&glDimension);
    return (*this);
}

void GLDimension::initialize(void)
{

}

void GLDimension::finalize(void)
{

}

void GLDimension::draw(void)
{
    double dx = this->xMax-this->xMin;
    double dy = this->yMax-this->yMin;
    double dz = this->zMax-this->zMin;

    double dmax = std::max(std::max(std::fabs(dx),std::fabs(dy)),std::fabs(dz));

    double scale = 0.1;

    double dxScale = scale*(dmax/std::fabs(dx));
    double dyScale = scale*(dmax/std::fabs(dy));
    double dzScale = scale*(dmax/std::fabs(dz));

    GLArrow(this->getGLWidget(),RR3Vector(this->xMin,this->yMin,this->zMin),RR3Vector( dx,0.0,0.0),true,true,dxScale).paint();
    GLArrow(this->getGLWidget(),RR3Vector(this->xMax,this->yMin,this->zMin),RR3Vector(-dx,0.0,0.0),true,true,dxScale).paint();

    this->getGLWidget()->renderText((this->xMin+this->xMax)/2.0,this->yMin,this->zMin,QString::number(dx),QFont("Courier",20));

    GLArrow(this->getGLWidget(),RR3Vector(this->xMin,this->yMin,this->zMin),RR3Vector(0.0, dy,0.0),true,true,dyScale).paint();
    GLArrow(this->getGLWidget(),RR3Vector(this->xMin,this->yMax,this->zMin),RR3Vector(0.0,-dy,0.0),true,true,dyScale).paint();

    this->getGLWidget()->renderText(this->xMin,(this->yMin+this->yMax)/2.0,this->zMin,QString::number(dy),QFont("Courier",20));

    GLArrow(this->getGLWidget(),RR3Vector(this->xMin,this->yMin,this->zMin),RR3Vector(0.0,0.0, dz),true,true,dzScale).paint();
    GLArrow(this->getGLWidget(),RR3Vector(this->xMin,this->yMin,this->zMax),RR3Vector(0.0,0.0,-dz),true,true,dzScale).paint();

    this->getGLWidget()->renderText(this->xMin,this->yMin,(this->zMin+this->zMax)/2.0,QString::number(dz),QFont("Courier",20));
}
