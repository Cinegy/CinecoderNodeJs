#Directory to start scan from
$rootPath = "."

$cinecoderVersion = "3.27.39.11441"

$currentYear = (Get-Date).year

#Root directory filter (can be set to just "" to ignore)
$rootDirFilter = "" 

$filesToImprint = ".cs", ".idl", ".h", ".c"

$license = 
@"
/* Copyright $currentYear Cinegy GmbH.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  The version of Cinecoder for these headers should be: $cinecoderVersion
*/

"@

$subfiles = Get-ChildItem -Recurse -Path $rootPath | where { ! $_.PSIsContainer} 

foreach($file in $subfiles)
{
    if($filesToImprint -contains $file.Extension)
    { 
        $fileContent = Get-Content $file.FullName

        if($fileContent.Contains("Copyright $currentYear Cinegy GmbH") -eq $false)
        {
            $modName = $file.FullName
            $license | Out-File -FilePath $modName -Encoding utf8
            $fileContent | Out-File -FilePath $modName -Encoding utf8 -Append
        }
    }
}