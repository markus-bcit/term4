List files and their size (GB)
```powershell
Function Get-FolderSizes {
    Get-ChildItem -Directory -ErrorAction SilentlyContinue | ForEach-Object {
        try {
            $folderPath = $_.FullName
            $folderSize = Get-ChildItem -Path $folderPath -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum -ErrorAction SilentlyContinue
            if ($folderSize) {
                [PSCustomObject]@{
                    Folder = $folderPath
                    Size_GB = [math]::Round($folderSize.Sum / 1GB, 2)
                }
            }
        } catch {
            Write-Host "Error accessing folder: $($_.FullName)"
        }
    }
}

Set-Alias -Name Get-FolderSizesAlias -Value Get-FolderSizes

```

undo local commits and keep changes
```powershell
git reset --soft HEAD^
```

Git LFS
- Install
```powershell
git lfs install
```
- Track
```powershell
git lfs track "large_file.bin"
```
- commit and push

Keypair
```bash
#makes a key named 4640-key to ~/.ssh/
ssh-keygen -C "4640-key" -f ~/.ssh/4640-key -m PEM -t ed25519 -N ''
```

COMP 2121 Quiz Mark Correction
Hi Jason,  
  
Please find the attached image (quiz2.JPEG) of the quiz 2 mark correction we discussed in class today.  
  
Thanks,  
  
Markus Afonso  
A01333486