/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CC_FILEUTILS_ANDROID_H__
#define __CC_FILEUTILS_ANDROID_H__

#include "platform/CCFileUtils.h"
#include "CCPlatformMacros.h"
#include "ccTypes.h"
#include <string>
#include <vector>
#include "jni.h"
#include "android/asset_manager.h"

NS_CC_BEGIN

/**
 * @addtogroup platform
 * @{
 */

//! @brief  Helper class to handle file operations
class CC_DLL FileUtilsAndroid : public FileUtils
{
    friend class FileUtils;
    FileUtilsAndroid();
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~FileUtilsAndroid();

    static void setassetmanager(AAssetManager* a);

    /* override funtions */
    bool init();
    virtual unsigned char* getFileData(const char* filename, const char* mode, long * size);

    virtual std::string getWritablePath() const;
    virtual bool isFileExist(const std::string& strFilePath) const;
    virtual bool isAbsolutePath(const std::string& strPath) const;
    
    /** This function is android specific. It is used for TextureCache::addImageAsync(). 
     Don't use it in your codes.
     */
    unsigned char* getFileDataForAsync(const char* filename, const char* mode, long * size);
    
private:
    unsigned char* doGetFileData(const char* filename, const char* mode, long * size, bool forAsync);
    static AAssetManager* assetmanager;
};

// end of platform group
/// @}

NS_CC_END

#endif    // __CC_FILEUTILS_ANDROID_H__
