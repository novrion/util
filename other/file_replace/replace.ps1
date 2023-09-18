# Replace ('¯', '-') with ('OLD_VALUE', 'NEW_VALUE')
Get-ChildItem -Path ".\" -Recurse -Exclude *.ps1 | ForEach-Object {Set-Content -Path $_ -Value (Get-Content -Path $_).replace('¯', '-')}
