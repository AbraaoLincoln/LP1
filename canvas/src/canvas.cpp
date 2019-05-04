#include "../include/canvas.h"
#include "../include/common.h"

using namespace life;

void Canvas::pixel(const Point2& p, const Color& c)
{
    auto index{p.y*(m_width*image_depth*m_block_size)+(p.x*(image_depth*m_block_size))};

    for(auto i{0}; i < m_block_size;i++)
    {
        for(auto j{0};j < m_block_size;j++)
        {
            m_pixels[index] = c.channels[0];
            m_pixels[index+1] = c.channels[1];
            m_pixels[index+2] = c.channels[2];
            m_pixels[index+3] = 255;
            index += 4;
        }
        index += ((m_width*image_depth)-(m_block_size*image_depth));
    }
}