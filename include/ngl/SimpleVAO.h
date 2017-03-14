/*
  Copyright (C) 2016 Jon Macey

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEVAO_H_
#define SIMPLEVAO_H_

#include "AbstractVAO.h"
#include <pybind11/pybind11.h>
namespace ngl
{
//----------------------------------------------------------------------------------------------------------------------
/// @class SimpleVAO "include/SimpleVAO.h"
/// @brief Simple non index vao using one buffer and float data
/// see https://github.com/NCCA/VertexArrayObject/tree/master/SimpleVAOFactory
/// for examples of use
/// @author Jonathan Macey
/// @version 1.0
/// @date 6/4/16
//----------------------------------------------------------------------------------------------------------------------

class NGL_DLLEXPORT SimpleVAO : public AbstractVAO
{
  public :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief creator method for the factory
    /// @param _mode the mode to draw with.
    /// @returns a new AbstractVAO * object
    //----------------------------------------------------------------------------------------------------------------------
    static AbstractVAO *create(GLenum _mode=GL_TRIANGLES) { return new SimpleVAO(_mode); }
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief draw the VAO using glDrawArrays
    //----------------------------------------------------------------------------------------------------------------------
    virtual void draw() const;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor clears the VAO data
    //----------------------------------------------------------------------------------------------------------------------
    virtual ~SimpleVAO();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief remove the VAO and buffers created
    //----------------------------------------------------------------------------------------------------------------------
    virtual void removeVAO();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief, this method sets the data for the VAO if data has already been set it will remove the existing data
    /// and then re-set with the new data.
    //----------------------------------------------------------------------------------------------------------------------
    virtual void setData(const VertexData &_data);
    virtual void setData(pybind11::list _data);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief return the id of the buffer, if there is only 1 buffer just return this
    /// if we have the more than one buffer the sub class manages the id's
    /// @param _buffer index (default to 0 for single buffer VAO's)
    //----------------------------------------------------------------------------------------------------------------------
     GLuint getBufferID(unsigned int ){return m_buffer;}

  protected :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor calles parent ctor to allocate vao;
    //----------------------------------------------------------------------------------------------------------------------
    SimpleVAO(GLenum _mode)  : AbstractVAO(_mode)
    {

    }

  private :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the id of the buffer for the VAO
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_buffer=0;

};


} // end namespace

#endif
