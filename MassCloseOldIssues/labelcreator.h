/* MIT License

Copyright (c) 2020 sledgehammer999 <hammered999@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class ProgramOptions;
class PostDownloader;

class LabelCreator
{
public:
    // The passed arguments must outlive the class instance
    explicit LabelCreator(const ProgramOptions &programOptions, PostDownloader &downloader, std::string_view repoID,
                          std::string &error);

    void run();
    std::string labelId() const;

private:
    void onFinishedPage();

    void gatherLabelID(std::string_view response);
    std::string makeLabelAlias(const int counter, const std::string &name);

    const ProgramOptions &m_programOptions;
    PostDownloader &m_downloader;
    const std::string m_repoID;
    std::string m_labelID;
    std::string &m_error;
};
