--Funcao que encontra a sopreposicao de duas strings
function findOverlappingPair(a, b)
  local max = math.mininteger
  local n = math.min(string.len(a), string.len(b))
  local c = ""
  
  for i=2, (n+1) do
    print(string.sub(a,-(i-1)))
    if (string.sub(a,-(i-1)) == string.sub(b,i)) then
      if max < i then
        max = i
        c = a .. string.sub(b, i)
      end
    end
  end
  
  for i=2, (n+1) do
    if (string.sub(a,i) == string.sub(b,-(i-1))) then
      if max < i then
        max = i
        c = b .. string.sub(a,i)
      end
    end
  end
  return max, c
end


function findShortestSuperstring(list)
  local list_len = #list
  while list_len ~= 1 do
    max = math.mininteger
    local p = -1; local q = -1
    local final_str = ""
    print("LISTA MT LOKA: " .. list[1])
    for i=1, (list_len) do
      for j = (i+1), (list_len) do
        local c
        max_len, c = findOverlappingPair(list[i],list[j])
        if max < max_len then
          max = max_len
          final_str = c
          p = i
          q = j
        end
        
      end
      
    end
  
    list_len = list_len - 1
  
    if max == math.mininteger then
      list[1] = list[1] .. list[list_len]
    else
      list[p] = final_str
      list[q] = list[list_len]
    end
    
  end
  
  return list[1]
  
end

function main()
LIST = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"}
print(findShortestSuperstring(LIST))
end
main()