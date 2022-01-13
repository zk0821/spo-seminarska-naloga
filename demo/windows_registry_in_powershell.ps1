<#Nov kljuc SPO#>
New-Item -Path HKCU:\SOFTWARE -Name SPO
<#Nov kljuc PowerShell#>
New-Item -Path HKCU:\SOFTWARE\SPO -Name PowerShell
<#Uspesna transakcija#>
Start-Transaction
New-ItemProperty -Path HKCU:\SOFTWARE\SPO\PowerShell -Name UspesnaTransakcija -PropertyType String -Value "Vrednost uspesno dodana preko PowerShell skripte" -UseTransaction
Complete-Transaction
<#Neuspesna transakcija#>
Start-Transaction
New-ItemProperty -Path HKCU:\SOFTWARE\SPO\PowerShell -Name NeuspesnaTransakcija -PropertyType String -Value "Should not exist" -UseTransaction
Undo-Transaction
Start-Sleep -s 10